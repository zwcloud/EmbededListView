#include "SubListModel.h"

MyObject* SubListModel::getObj()
{
    return m_object;
}

int SubListModel::rowCount(const QModelIndex& parent) const
{
    return m_object->m_values.size();
}

constexpr int ObjectIndexRole = Qt::UserRole + 1;
constexpr int ValueRole = Qt::UserRole + 2;
QHash<int, QByteArray> SubListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ObjectIndexRole] = "obj_index";
    roles[ValueRole] = "int_value";
    return roles;
}

QVariant SubListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= m_object->m_values.size())
    {
        return QVariant();
    }

    if (role == ObjectIndexRole)
    {
        return m_object->m_index;
    }

    if (role == ValueRole)
    {
        return m_object->m_values[index.row()];
    }

    return QVariant();
}

SubListModel::SubListModel(MyObject* obj) : m_object(obj)
{
}
