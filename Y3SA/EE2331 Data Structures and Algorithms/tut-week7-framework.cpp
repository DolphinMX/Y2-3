#include <iostream>
#include <fstream>

using namespace std;

struct ListNode
{
    int info;
    ListNode *link;
};

void append(ListNode *&head, int x)
{
    ListNode *p = new ListNode;
    p->info = x;
    p->link = NULL;

    if (head == NULL)
    {
        p->link = head;
        head = p;
    }
    else
    {
        ListNode *prev = head;
        ListNode *cur = head->link;

        while (cur != NULL)
        {
            prev = cur;
            cur = cur->link;
        }

        p->link = prev->link;
        prev->link = p;
    }
}

ListNode *initialize_list(string s)
{
    ListNode *head = NULL;
    ifstream inFile(s);

    if (!inFile.is_open())
    {
        cout << "Error: cannot open data file" << endl;
        return head; // Return the empty list
    }

    while (!inFile.eof())
    {
        int i;
        inFile >> i;

        if (!inFile.fail())
            append(head, i);
        else
            break;
    }

    inFile.close();
    return head;
}

void print(ListNode *head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        cout << cur->info << " ";
        cur = cur->link;
    }
    cout << endl;
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode *mergedHead = NULL;
    ListNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->info <= head2->info)
        {
            if (mergedHead == NULL)
            {
                mergedHead = tail = head1;
            }
            else
            {
                tail->link = head1;
                tail = tail->link;
            }
            head1 = head1->link;
        }
        else
        {
            if (mergedHead == NULL)
            {
                mergedHead = tail = head2;
            }
            else
            {
                tail->link = head2;
                tail = tail->link;
            }
            head2 = head2->link;
        }
    }

    if (head1 != NULL)
    {
        if (mergedHead == NULL)
        {
            mergedHead = tail = head1;
        }
        else
        {
            tail->link = head1;
        }
    }

    if (head2 != NULL)
    {
        if (mergedHead == NULL)
        {
            mergedHead = tail = head2;
        }
        else
        {
            tail->link = head2;
        }
    }

    // Sort the merged list using insertion sort
    ListNode *sortedHead = NULL;
    ListNode *cur = mergedHead;

    while (cur != NULL)
    {
        ListNode *next = cur->link;

        if (sortedHead == NULL || cur->info < sortedHead->info)
        {
            // Insert at the beginning of the sorted list
            cur->link = sortedHead;
            sortedHead = cur;
        }
        else
        {
            ListNode *sortCur = sortedHead;
            while (sortCur->link != NULL && sortCur->link->info < cur->info)
            {
                sortCur = sortCur->link;
            }
            cur->link = sortCur->link;
            sortCur->link = cur;
        }

        cur = next;
    }

    return sortedHead;
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = initialize_list("sortA.txt");
    head2 = initialize_list("sortB.txt");

    if (head1 == NULL || head2 == NULL)
    {
        cout << "One or both of the lists are empty. Aborting." << endl;
        return 0;
    }

    cout << "Contents of list A: ";
    print(head1);
    cout << "Contents of list B: ";
    print(head2);

    ListNode *new_head = merge(head1, head2);

    cout << "Merged list: ";
    print(new_head);

    return 0;
}