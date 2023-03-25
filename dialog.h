#ifndef DIALOG_H
#define DIALOG_H

#include <QTreeWidget>
#include <QDialog>
#include <QFileInfo>
#include <QDir>
#include <QClipboard>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    const QString &getListString() const;
    void setListString(const QString &newListString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemExpanded(QTreeWidgetItem *item);

private:
    Ui::Dialog *ui;

    void addRoots();

        QTreeWidgetItem *createItem(QFileInfo fi);
        void addExpander(QTreeWidgetItem *root);
        void addChildren(QTreeWidgetItem *root);
        void setCheckState(QTreeWidgetItem *root, Qt::CheckState state);
        void getCheckedItems(QTreeWidgetItem *root);
        void getCheckedItems();
};
#endif // DIALOG_H
