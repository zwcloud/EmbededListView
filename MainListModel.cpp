#include "MainListModel.h"
#include "MyObject.h"
#include "SubListModel.h"

void MainListModel::fill(std::vector<MyObject*>& objectList)
{
    beginResetModel();
    //clear old sub-models
    for (SubListModel* model : m_children)
    {
        delete model;
        model = nullptr;
    }
    m_children.clear();
    //create new sub-models
    for (int i=0; i<objectList.size(); ++i)
    {
        MyObject* obj = objectList[i];
        SubListModel* subListModel = new SubListModel(obj);
        m_children.append(subListModel);
    }
    endResetModel();
}

int MainListModel::rowCount(const QModelIndex& parent) const
{
    return m_children.size();
}

constexpr int ObjNameRole = Qt::UserRole + 1;
constexpr int ObjValuesRole = Qt::UserRole + 2;
QHash<int, QByteArray> MainListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ObjNameRole] = "obj_name";
    roles[ObjValuesRole] = "obj_values";
    return roles;
}

QVariant MainListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= m_children.size())
    {
        return QVariant();
    }

    if (role == ObjNameRole)
    {
        return QString::fromStdString(m_children[index.row()]->getObj()->m_name);
    }

    if(role == ObjValuesRole)
    {
        return QVariant::fromValue(m_children[index.row()]);
    }

    return QVariant();
}
