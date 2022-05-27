#include <iostream>

using namespace std;

typedef struct knot_
{
    int key;
    // any
    knot_ * next;
}knot;

knot* initial_pointer() 
{
    knot* temp = new knot;
    temp->key = 0;
    temp->next = NULL;
    return temp;
}

knot* create_knot(int key)
{
    knot* temp = new knot;
    temp->key = key;
    // any
    temp->next = NULL;
}

int search(knot* ptlist ,knot** ant, knot** pont, int key) 
{
    knot* ptr;
    *ant = ptlist;
    ptr = ptlist->next;
    *pont = NULL;
    while (ptr)
    {
        if (ptr->key < key) 
        {
            *ant = ptr;
            ptr = ptr->next;
        } else {
            if (ptr->key == key) {
                *pont = ptr;
            } 
            ptr = NULL;
        }
    }
}

int insertion(knot* ptlist, int key) 
{
    int condition;
    knot* ant;
    knot* pont;

    search(ptlist, &ant, &pont, key);

    if (!pont) {
        knot* temp = create_knot(key);
        temp->next = ant->next;
        ant->next = temp;
        condition = 0;
    } else {
        cout << "The key was found in the list!" << endl;
        condition = -1;
    }
    return condition;
}

int remotion(knot* ptlist, int key)
{
    int condition;
    knot* ant;
    knot* pont;

    search(ptlist, &ant, &pont, key);

    if (pont) {
        ant->next = pont->next;
        condition = 0;
    } else {
        cout << "The key was not found in the list!" << endl;
        condition = -1;
    }
    return condition;

}

void print(knot* ptlist)
{
    knot* temp = ptlist->next;
    while (temp)
    {
        cout << "Key: " << temp->key << endl;
        temp = temp->next;
    }
}

void clear(knot* ptlist)
{
    knot* temp1 = ptlist;
    knot* temp2 = ptlist->next;
    while (temp2)
    {
        free(temp1);
        temp1 = temp2;
        temp2 = temp2->next;
    }
    free(temp2);
}

int main (void) 
{
    knot* ptlist;
    ptlist = initial_pointer();
    
    clear(ptlist);
    return 0;
}
