#include <iostream>
#include <vector>
using namespace std;

struct ComponentNode{
    int val;
    vector<ComponentNode*> child;
    ComponentNode(int v): val(v){}
};

struct Record{
    int cnt;
    int sum;
    Record(int c = 0, int s = 0): cnt(c), sum(s) {}
};

Record helper(ComponentNode* root, ComponentNode* &max_root, Record &max_rec) {
    if (!root) return Record();
    int sum = root->val;
    int cnt = 1;
    for (int i = 0; i < root->child.size(); ++i) {
        ComponentNode* nxt = root->child[i];
        Record rec = helper(nxt, max_root, max_rec);
        sum += rec.sum;
        cnt += rec.cnt;
    }
    Record crt(cnt, sum);
    if (cnt > 1 && sum * max_rec.cnt >= max_rec.sum * cnt) {
        max_rec = crt;    
        max_root = root;
    }
    return crt;
}


ComponentNode* max_avg_root(ComponentNode* root){
    if (!root) return NULL;
    ComponentNode* max_root;
    Record max_rec(1, 0);
    helper(root, max_root, max_rec);
    cout << "max avg:" << max_rec.sum / max_rec.cnt << endl;
    return max_root;
}


int main(int argc, char *argv[]) {
    ComponentNode* node0 = new ComponentNode(200);
    ComponentNode* node1 = new ComponentNode(120);
    ComponentNode* node2 = new ComponentNode(180);
    ComponentNode* node3 = new ComponentNode(110);
    ComponentNode* node4 = new ComponentNode(20);
    ComponentNode* node5 = new ComponentNode(30);
    ComponentNode* node6 = new ComponentNode(150);
    ComponentNode* node7 = new ComponentNode(80);
    
    node0->child.push_back(node1);
    node0->child.push_back(node2);
    node1->child.push_back(node3);
    node1->child.push_back(node4);
    node1->child.push_back(node5);
    node2->child.push_back(node6);
    node2->child.push_back(node7);
    
    ComponentNode* res_root = max_avg_root(node0);
    cout << "max avg root: " << res_root->val << endl;
    
}
