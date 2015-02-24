#include "map.h"
#include <QDebug>
Map::Map(){}
Map::Map(QString filename){
    Types["wall"] =  QBrush(Qt::red);
    Types["water"] =  QBrush(Qt::blue);
    Types["free"] =  QBrush(Qt::white,Qt::DiagCrossPattern);
    Types["grass"] = QBrush(Qt::green);
    Types["stone"] = QBrush(Qt::lightGray);
    Types["wood"] = QBrush(QColor(139,69,19));
    Types["quad"] = QBrush(Qt::black,Qt::CrossPattern);
    Types["avu"] = QBrush(Qt::darkYellow,Qt::CrossPattern);


    QFile loadFile(QDir::currentPath() + "/maps/" + filename );
    if(loadFile.exists()){
        loadFile.open(QIODevice::ReadOnly);
        QJsonDocument file(QJsonDocument::fromJson(loadFile.readAll()));
        QJsonObject mainJson(file.object());
        QJsonObject subJson(mainJson["map"].toObject());
        if(!subJson.isEmpty()){
            height = subJson["height"].toInt();
            width = subJson["width"].toInt();
            QJsonArray rows = subJson["rows"].toArray();
            for(int i = 0; i < height; i ++){
                QJsonArray cellArray = rows[i].toObject()["row"].toArray();
                for(int j = 0; j < width; j++){
                    QJsonObject cell = cellArray[j].toObject();
                    QJsonArray cellTypes = cell["cell"].toArray();
                    array[i][j] = cellTypes;
                }
            }
         }
    }
}

Map::Map(int height, int width,QJsonObject json):
    height(height),
    width(width)
{
    Types["wall"] =  QBrush(Qt::red);
    Types["water"] =  QBrush(Qt::blue);
    Types["free"] =  QBrush(Qt::white,Qt::DiagCrossPattern);
    Types["grass"] = QBrush(Qt::green);
    Types["stone"] = QBrush(Qt::lightGray);
    Types["wood"] = QBrush(QColor(139,69,19));
    Types["quad"] = QBrush(Qt::black,Qt::CrossPattern);
    Types["avu"] = QBrush(Qt::darkYellow,Qt::CrossPattern);

        for(int i = 0; i<height; i++){
            for(int j = 0; j<width;j++){
                array[i][j] = QJsonArray() ;
            }
        }
}
std::map<QString, QBrush> Map::getTypes(){
    return Types;
}

QBrush Map::getType(QString type){
    return Types[type];
}

QJsonArray Map::getPixel(int x,int y){
    return array[x][y];
}

void Map::setPixel(int x,int y, QJsonObject json){
    array[y/(480/height)][x/(480/width)].append(json);
}

void Map::deletePixel(int x, int y){
    array[y/(480/height)][x/(480/width)] = QJsonArray();
}
int Map::getHeight(){
    return height;
}

int Map::getWidth(){
    return width;
}

void Map::saveFile(QString filename){
    QJsonObject main;
    QJsonObject sub;
    QJsonArray rows;
    sub["title"] = filename;
    sub["width"] = width;
    sub["height"] = height;
    QJsonObject *row;
    QJsonArray *cellArray;
    QJsonObject *cell;
    for(int i = 0; i < height; i ++){
        row = new QJsonObject;
        cellArray = new QJsonArray;
        for(int j = 0; j < width; j++){
            cell = new QJsonObject;
            cell->insert("cell",array[i][j]);
            cellArray->append(*cell);
        }
        row->insert("row",*cellArray);
        rows.append(*row);
    }
    sub["rows"] = rows;
    main["map"] = sub;
    QFile * file;
    if(filename.contains(".map")){
         file = new QFile("maps/"+filename);
         qDebug() << "maps/" << filename;
    } else {
       file = new QFile("maps/"+filename + ".map");

        qDebug() << "maps/" << filename;
    }
    QJsonDocument saveDoc(main);
    file->open(QIODevice::WriteOnly);
    file->write(saveDoc.toJson());

}

Map::~Map()
{

}

