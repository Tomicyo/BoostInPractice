#include <iostream>
#include <vector>
#include <boost/pool/object_pool.hpp>

using namespace boost;
using namespace std;

class Pt2D
{
public:
    Pt2D()
    {
        cout << "construct Pt2D" << endl;
    }
    int x;
    int y;
    ~Pt2D()
    {
        cout << "deconstruct Pt2D" << endl;
    }
};

class Line
{
public:
    Line()
    {
        cout << "construct Pt3D" << endl;
    }
};

void TestObjPool()
{
    boost::object_pool<Pt2D> pool;
    const int SIZE = 10;
    vector<Pt2D *> vec;
    for(int i=0; i<SIZE; ++i)
    {
        Pt2D * pt = (Pt2D * )pool.malloc();
        vec.push_back(pt);
        pt->x =i;
        pt->y = -i;
    }
    
    cout << "test object pool" << endl;
    vector<Pt2D *>::iterator itSt, itEnd;
    for(itSt = vec.begin(), itEnd = vec.end();
        itSt != itEnd; ++itSt)
    {
        cout <<"X= " << (*itSt)->x<< " Y= "<<(*itSt)->y << endl;
    }
    boost::object_pool<Line> linesPool;
    for(int i=0; i<SIZE; ++i)
    {
        Line * line = linesPool.construct();
    }
}

void TestPool()
{
    boost::pool< > pool(sizeof(int));
    const int SIZE = 10;
    int   * ptrs[SIZE];
    int ** ptr = &ptrs[0];
    for(int i=0; i<SIZE; ++i)
    {
        (*ptr) = (int *)pool.malloc();
        ++ptr;
    }
    for(int i=0; i<SIZE; ++i)
    {
        *ptrs[i] = i;
    }
    
    for(int i=0; i<SIZE; ++i)
    {
        cout << *ptrs[i] << endl;
    }
    //pool的析构函数会释放所有从系统申请到的内存
    //因pool被分配栈上，所以当退栈后，自动调用其析构函数
    //即分配在pool上的众多小对象不用手动释放内存
}

int main()
{
    TestPool();
    TestObjPool();
    return 0;
}