#include "ListViewWidget.h"

ListViewWidget::ListViewWidget(ProductsModel* model, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.productsListView->setModel(model);

}

ListViewWidget::~ListViewWidget()
{
}
