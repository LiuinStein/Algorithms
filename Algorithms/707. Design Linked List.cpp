static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyLinkedList {

    ListNode *head;
    ListNode *tail;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->next = nullptr;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index + 1 > size || index < 0)
        {
            return -1;
        }
        ListNode *dummy{ head->next };
        while (index--)
        {
            dummy = dummy->next;
        }
        return dummy->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head->val = val;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail->val = val;
        ListNode *dummy = new ListNode(0);
        tail->next = dummy;
        tail = dummy;
        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index > size || index < 0)
        {
            return;
        }
        ListNode *dummy{ head };
        while (index--)
        {
            dummy = dummy->next;
        }
        ListNode *element = new ListNode(val);
        element->next = dummy->next;
        dummy->next = element;
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index + 1 > size || index < 0)
        {
            return;
        }
        ListNode *dummy{ head };
        while (index--)
        {
            dummy = dummy->next;
        }
        ListNode *deleted = dummy->next;
        dummy->next = deleted->next;
        deleted->next = nullptr;
        delete deleted;
        --size;
    }
};


// test code
int main() {
    std::string cmd, data;
    while (true)
    {
        std::cin >> cmd >> data;
        cmd = cmd.substr(1, cmd.length() - 2);
        data = data.substr(1, data.length() - 2);
        stringstream scmd, dcmd;
        scmd.str(cmd);
        dcmd.str(data);
        string citem, ditem;
        char delim = ',';
        MyLinkedList linkedList;
        while (getline(scmd, citem, delim) && getline(dcmd, ditem, ',')) {
            //std::cout << citem << " " << ditem << std::endl;
            if (citem == "\"addAtHead\"")
            {
                linkedList.addAtHead(stoi(ditem.substr(1, ditem.length() - 2)));
            }
            else if (citem == "\"addAtTail\"")
            {
                linkedList.addAtTail(stoi(ditem.substr(1, ditem.length() - 2)));
            }
            else if (citem == "\"addAtIndex\"")
            {
                int first = stoi(ditem.substr(1));
                getline(dcmd, ditem, ',');
                int second = stoi(ditem.substr(0, ditem.size() - 1));
                linkedList.addAtIndex(first, second);
            }
            else if (citem == "\"get\"")
            {
                std::cout << linkedList.get(stoi(ditem.substr(1, ditem.length() - 2))) << std::endl;
            }
            else if (citem == "\"deleteAtIndex\"")
            {
                linkedList.deleteAtIndex(stoi(ditem.substr(1, ditem.length() - 2)));
            }
        }
    }
    return 0;
}