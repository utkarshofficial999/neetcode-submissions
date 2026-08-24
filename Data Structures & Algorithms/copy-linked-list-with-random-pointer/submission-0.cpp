class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        if (mp.count(head))
            return mp[head];

        Node* copy = new Node(head->val);

        
        mp[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }
};