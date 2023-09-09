#include "AVL.hpp"
int main()
{
    //int a[]={16, 3, 7, 11, 9, 26, 18, 14, 15};
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    AVLTree<int, int> avl1;
    for (auto e : a)
        avl1.Insert(make_pair(e, e));

    avl1.InOrder();

    cout << "IsBlance:" << avl1.IsBalance() << endl;
    return 0;
}
