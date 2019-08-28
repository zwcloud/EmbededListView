#pragma once
#include <QAbstractListModel>
#include "MyObject.h"

class SubListModel : public QAbstractListModel
{
public:
    SubListModel(MyObject* obj);
    MyObject* getObj();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    MyObject* m_object;
};
