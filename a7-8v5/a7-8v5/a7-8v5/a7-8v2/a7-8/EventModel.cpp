#include "EventModel.h"
#include <QFont>
#include <QBrush>

ProductsModel::ProductsModel(Agenda& agenda): agenda{agenda}
{
}

int ProductsModel::rowCount(const QModelIndex& parent) const
{
    return this->agenda.get_nr_of_event();
}

int ProductsModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}

QVariant ProductsModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int column = index.column();

    Event p = this->agenda.get_all_events()[row];


    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
        case 0:
            return QString::fromStdString(p.get_title());
        case 1:
            return QString::number(p.get_number_of_people());
        default:
            break;
        }
    }

    if (role == Qt::FontRole)
    {
        QFont font{ "Verdana", 15 };
        return font;
    }

    if (role == Qt::BackgroundRole)
    {
        if (row % 2 == 1)
        {
            QBrush brush{ QColor{220, 220, 220} };
            return brush;
        }
    }

    if (role == Qt::UserRole)
        if (column == 1)
            return p.get_number_of_people();

    return QVariant();
}

QVariant ProductsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            switch (section)
            {
            case 0:
                return QString{ "Title" };
            case 1:
                return QString{ "Participants" };
            default:
                break;
            }
        }
    }

    return QVariant();
}

//void ProductsModel::addProduct(const Event& p)
//{
//	int n = this->repo.get_number_of_Events();

//	this->beginInsertRows(QModelIndex{}, n, n);

//	this->repo.add_Event(p);

//	this->endInsertRows();
//}

//void ProductsModel::clearData()
//{
//	this->beginResetModel();

//	this->repo.clear();

//	this->endResetModel();
//}
