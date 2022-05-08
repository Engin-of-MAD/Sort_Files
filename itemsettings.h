#ifndef ITEMSETTINGS_H
#define ITEMSETTINGS_H
#include "menu.h"
#include "filesearch.h"
class ItemSettings : public Item{
public:

    void initData(FileSearch* file);
    void showData() override;
    void setInPath() override;
    void setOutPath() override;
    void setExtd() override;
    void setLabel() override;
};

#endif // ITEMSETTINGS_H
