#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node(string v) {
        this->val = v;
        this->next = NULL;
    }
};

void display(Node* head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}

static inline bool isVowel(const string& s) {
    if (s.empty()) return false;
    char c = tolower(s[0]);
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

Node* solve(Node* head) {
    Node* lo = new Node("q");   // vowel dummy
    Node* hi = new Node("a");   // consonant dummy
    Node* tl = lo;              // vowel tail
    Node* th = hi;              // consonant tail

    Node* temp = head;
    while (temp != NULL) {
        Node* nxt = temp->next;   // cache next
        temp->next = NULL;        // detach

        if (isVowel(temp->val)) {
            tl->next = temp;      // append current node
            tl = tl->next;
        } else {
            th->next = temp;      // append current node
            th = th->next;
        }
        temp = nxt;
    }

    tl->next = hi->next;          // connect lists
    Node* newHead = lo->next;     // head of result

    // No deletion of dummy nodes per request
    return newHead;
}

int main() {
    Node* a = new Node("a");
    Node* b = new Node("b");
    Node* c = new Node("c");
    Node* d = new Node("d");
    Node* e = new Node("e");
    Node* f = new Node("f");
    Node* g = new Node("g");
    Node* h = new Node("h");
    Node* i = new Node("i");

    a->next=b; b->next=c; c->next=d; d->next=e; e->next=f; f->next=g; g->next=h; h->next=i; i->next=NULL;

    Node* head = solve(a);
    display(head);
    return 0;
}