#pragma once
#include <QAbstractTableModel>
#include "Repo.h"
#include "Agenda.h"

class ProductsModel : public QAbstractTableModel
{
private:
    //Repo& repo;
    Agenda& agenda;

public:
    ProductsModel(Agenda& agenda);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//	void addProduct(const Event& p);
//	void clearData();
};
