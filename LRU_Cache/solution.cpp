#include<iostream>
#include<vector>
#include<map>

using namespace std;

class LRUCache
{
	private:
		int capacity;
		int capacity_cur;
		typedef struct ListNode
		{
			int key;
			int value;
			struct ListNode* next;
			struct ListNode* pre;
			ListNode(int k , int v):key(k),value(v),next(NULL),pre(NULL) {}
		}ListNode;
		ListNode *head;

		typedef struct Value
		{
			int val;
			ListNode *p;
			Value(int _v,ListNode *pp):val(_v),p(pp){}
			Value() {}  //if this constructor is not defined,there will be wrong
		}tValue;
		map< int,tValue > mkv;
		map< int,tValue > :: iterator it;

	public:
		LRUCache(int capacity)
		{
			this->capacity = capacity;
			head = new ListNode(0,0);
			capacity_cur = 0;
		}

		int get(int key)
		{
			if( is_exist(key) )  
			{
				//get down the loc node
				ListNode *loc = mkv[key].p;
				loc->pre->next = loc->next;
				loc->next->pre = loc->pre;

				//insert into the front of the head
				loc->next = head->next;
				loc->pre = head;
				head->next = loc;
				loc->next->pre = loc;

				return mkv[key].val;
			}
			else
			{
				return -1;
			}
		}

		void set(int key , int value)
		{	
			if(  is_exist(key) ) 
			{
				//change the value in map and the list
				mkv[key].val = value;
				ListNode *q = mkv[key].p;
				q->value = value;

				//get the node and insert into the head of the list
				q->pre->next = q->next;
				q->next->pre = q->pre;

				q->next = head->next;
				q->pre = head;
				head->next->pre = q;
				head->next = q;

				return ;
			}

			ListNode *tmp = new ListNode(key,value);
			if(capacity_cur<capacity)
			{
				if(head->next==NULL) //the list is empty
				{
					head->next = tmp ;
					head->pre = tmp;
					tmp->next = head;
					tmp->pre = head;
					tValue tv(value,tmp);
					mkv[key] = tv;
					++capacity_cur;
				}
				else //insert the tmp into the front of the list
				{
					tmp->next = head->next;
					tmp->pre = head;
					head->next->pre = tmp;
					head->next = tmp;
					tValue tv(value,tmp);
					mkv[key] = tv;
					++capacity_cur;
				}
			}
			else
			{
				//get rid of the lru node
				ListNode *tail = head->pre;
				head->pre = tail->pre;
				tail->pre->next = head;
				mkv.erase(tail->key);
				delete tail;

				//insert into the new node
				tmp->next = head->next;
				tmp->pre = head;
				head->next->pre = tmp;
				head->next = tmp;
				tValue tv(value,tmp);
				mkv[key] = tv;
			}
		}	

		bool is_exist(int key)
		{
			return ( mkv.find(key) != mkv.end() );
		}

		void print()
		{
			ListNode *p = head->next;
			while(p!=head)
			{
				cout<<"key = "<<p->key<<" Value = "<<p->value<<endl;
				p = p->next;
			}
			cout<<endl;
		}
};

int main()
{
	/*
	   LRUCache lru(3);
	   lru.set(1,10);
	   lru.print();
	   lru.set(2,20);
	   lru.print();
	   lru.set(3,30);
	   lru.print();
	   cout<<"get key = "<<1<<",Value = "<<lru.get(1)<<endl;
	   lru.print();
	   lru.set(4,40);
	   lru.print();
	   cout<<"get key = "<<3<<",Value = "<<lru.get(3)<<endl;
	   lru.print();
	   lru.set(5,50);
	   lru.print();
	   LRUCache lru1(2);
	   lru1.set(2,1);
	   lru1.print();
	   lru1.set(2,2);
	   lru1.print();
	   cout<<"get key = "<<2<<",Value = "<<lru1.get(2)<<endl;
	   lru1.set(1,1);
	   lru1.print();
	   lru1.set(4,1);
	   lru1.print();
	   cout<<"get key = "<<2<<",Value = "<<lru1.get(2)<<endl;
	   */
	LRUCache lru1(2);
	lru1.set(2,1);
	lru1.print();
	lru1.set(1,1);
	lru1.print();
	lru1.set(2,3);
	lru1.print();
	lru1.set(4,1);
	lru1.print();
	cout<<"get key = "<<1<<",Value = "<<lru1.get(1)<<endl;
	cout<<"get key = "<<2<<",Value = "<<lru1.get(2)<<endl;


	return 0;
}

