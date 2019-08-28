#pragma once
#include <QAbstractListModel>
#include <QVariant>
#include <QVector>
#include "MyObject.h"

class SubListModel;
class MainListModel : public QAbstractListModel
{
public:
    void fill(std::vector<MyObject*>& objectList);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QVector<SubListModel*> m_children;
};
