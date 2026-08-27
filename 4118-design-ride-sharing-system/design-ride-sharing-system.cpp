struct Node{
    int id;
    Node* next,*prev;
    Node(int id){
        this->id=id;
    }
};
class RideSharingSystem {
public:
    Node* rhead,*rtail,*dhead,*dtail;
    unordered_map<int,Node*>mp;
    void addll(Node* tail,Node* node){
        Node* prv=tail->prev;
        prv->next=node;
        node->prev=prv;
        node->next=tail;
        tail->prev=node;
    }
    void removell(Node* node){
        Node* nd=node->next;
        Node* head=node->prev;
        head->next=nd;
        nd->prev=head;
    }
    RideSharingSystem() {
        rhead=new Node(-1);
        rtail=new Node(-1);
        dhead=new Node(-1);
        dtail=new Node(-1);
        rhead->next=rtail;
        rtail->prev=rhead;
        dhead->next=dtail;
        dtail->prev=dhead;
    }
    
    void addRider(int riderId) {
        Node* rdr=new Node(riderId);
        mp[riderId]=rdr;
        addll(rtail,rdr);
    }
    
    void addDriver(int driverId) {
        Node* dvr=new Node(driverId);
        addll(dtail,dvr);
    }
    
    vector<int> matchDriverWithRider() {
        if(rhead->next==rtail || dhead->next==dtail) return {-1,-1};
        Node* a=dhead->next;
        Node* b=rhead->next;
        removell(a);
        removell(b);
        mp.erase(b->id);
        return {a->id,b->id};
    }
    
    void cancelRider(int riderId) {
        if(mp.count(riderId)){
            Node* rem=mp[riderId];
            removell(rem);
            mp.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */