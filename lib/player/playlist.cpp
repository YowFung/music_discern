#include "playlist.h"

PlayList::PlayList()
{
    loadList();
}

PlayList::~PlayList()
{
    saveList();
}

// 加载播放列表
void PlayList::loadList()
{

}

// 保存播放列表
void PlayList::saveList()
{

}

void PlayList::reload()
{
    struct item *p = items;
    int i = 0;
    while (p != nullptr) {
        p->id = i;
        i++;
        p = p->next;
    }
}

// 获取当前选中项目的 ID
int PlayList::currentRow()
{
    return currentItem->id;
}

// 获取项目总数
int PlayList::count()
{
    struct item *p = items;
    int count = 0;
    while (p != nullptr) {
        count++;
        p = p->next;
    }

    return count;
}

// 追加项目
bool PlayList::append(MidiFile midi)
{
    struct item *p = items, *obj;

    obj = (struct item *)malloc(sizeof(struct item));
    obj->midi = midi;

    if (items == nullptr) {
        items = obj;
        reload();
        return true;
    }
    else while (p != nullptr) {
        if (p->next == nullptr ) {
            p->next = obj;
            reload();
            return true;
        }

        p = p->next;
    }

    return false;
}

// 移除项目
bool PlayList::remove(int index)
{
    struct item *p = items, *temp;
    int i = 0;
    while (p != nullptr) {
        if (i+1 == index) {
            temp = p;
            p = p->next;
            temp->next = nullptr;
        }
        if (i == index) {
            temp->next = p->next;
            free(p);
            reload();
            return true;
        }

        i++;
        p = p->next;
    }

    return false;
}

// 选中项目
bool PlayList::selected(int index)
{
    currentItem = nullptr;
    struct item *p = items;

    while (p != nullptr) {
        if (index == p->id) {
            currentItem = p;
            return true;
        }
    }

    return false;
}
