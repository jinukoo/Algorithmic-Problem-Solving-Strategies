// Q: turn black-white picture(quad tree) upside down
// b - if all pixels under are black
// w - if all pixels under are white
// x - if pixels are not one color

// Idea : turn input into a quadtree
//        then reverse the tree

#include <iostream>

using namespace std;

// Quad Tree Class
class QuadTree{
public:
    // takes input string into a tree object
    QuadTree(string &colors){
        color = colors[0];
        colors.erase(colors.begin());
        if(color == 'x'){
            for(int i = 0; i < 4; i++){
                subtree[i] = new QuadTree(colors);
            }
        }
        else{
            for(auto x : subtree){
                x = nullptr;
            }
        }
    }

    void reverse();         // reverse the tree
    void print();           // prints the tree

    // if subtree is used, free the space
    ~QuadTree(){
        if(color == 'x'){
            for(auto x : subtree){
                delete x;
            }
        }
    }

private:
    char color;
    QuadTree* subtree[4];
};


int main(){
    int c;
    cin >> c;
    for(int i=0; i<c; i++){
        string s;
        cin >> s;
        QuadTree x(s);
        x.reverse();
        x.print();
        cout << endl;
    }
    return 0;
}


void QuadTree::print(){
    cout << color;
    if(color == 'x'){
        for(auto x : subtree){
            x->print();
        }
    }
}

void QuadTree::reverse(){
    // base case : subtrees are all one color
    if(color != 'x')
        return;
    else{
        swap(subtree[0], subtree[2]);
        swap(subtree[1], subtree[3]);
        for(auto x : subtree){
            x->reverse();
        }
    }
}
