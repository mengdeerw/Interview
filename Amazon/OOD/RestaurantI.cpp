/*
不能预订座位

不能订外卖

餐馆的桌子有不同大小

餐馆会优先选择适合当前Party最小的空桌（例如，如果客人一共有3个人，餐厅将分配一张4人的桌子，而不是10人的桌子）

需要实现Restaurant Class

每次调用findTable, takeOrder, checkOut之后都会调用restaurantDescription, 来验证你的程序是否正确。

样例
样例1

输入:
//创建三个菜
meal(10.0)
meal(13.0)
meal(17.0)

//创建三个桌子
table(4)
table(4)
table(10)

//输入备选的party
party(3)
party(7)
party(4)
party(6)
party(1)

//创建order
order(1)
order(2, 3)

//给第1，3，4的party安排桌子
findTable(1)
findTable(3)
findTable(4)

//第一桌点了第一个order
takeOrder(1, 1)

//第三桌点了第二个order
takeOrder(3, 2)

//第三桌checkout
checkOut(3)

//给第4个party安排桌子
findTable(4)

输出:
Table: 0, table size: 4, isAvailable: false. No current order for this table.
Table: 1, table size: 4, isAvailable: true. No current order for this table.
Table: 2, table size: 10, isAvailable: true. No current order for this table.
*****************************************

Table: 0, table size: 4, isAvailable: false. No current order for this table.
Table: 1, table size: 4, isAvailable: false. No current order for this table.
Table: 2, table size: 10, isAvailable: true. No current order for this table.
*****************************************

Table: 0, table size: 4, isAvailable: false. No current order for this table.
Table: 1, table size: 4, isAvailable: false. No current order for this table.
Table: 2, table size: 10, isAvailable: false. No current order for this table.
*****************************************

Table: 0, table size: 4, isAvailable: false. Order price: 10.0.
Table: 1, table size: 4, isAvailable: false. No current order for this table.
Table: 2, table size: 10, isAvailable: false. No current order for this table.
*****************************************

Table: 0, table size: 4, isAvailable: false. Order price: 10.0.
Table: 1, table size: 4, isAvailable: false. No current order for this table.
Table: 2, table size: 10, isAvailable: false. Order price: 30.0.
*****************************************

Table: 0, table size: 4, isAvailable: false. Order price: 10.0.
Table: 1, table size: 4, isAvailable: false. No current order for this table.
Table: 2, table size: 10, isAvailable: true. No current order for this table.
*****************************************

Table: 0, table size: 4, isAvailable: false. Order price: 10.0.
Table: 1, table size: 4, isAvailable: false. No current order for this table.
Table: 2, table size: 10, isAvailable: false. No current order for this table.
*****************************************

说明:
meal(x) 代表我们创建一个价格为x的菜品
样例2

输入:
meal(12.0)
table(4)
table(4)
table(10)
party(13)
findTable(1)

输出:
Table: 0, table size: 4, isAvailable: true. No current order for this table.
Table: 1, table size: 4, isAvailable: true. No current order for this table.
Table: 2, table size: 10, isAvailable: true. No current order for this table.
*****************************************

*/

class Meal {
private:
	float price;
	
public:
	Meal(float price) {
		this->price = price;
	}
	
	float getPrice() {
		return this->price;
	}
};

class Order {
private:
	vector<Meal*> *meals;
	
public:
	Order() {
		meals =new vector<Meal*>;
	}
	
	vector<Meal*>* getMeals() {
		return meals;
	}
	
	Order* mergeOrder(Order *order) {
		Order* ans = new Order;
		for(Meal* &meal : *(this->getMeals())) {
			ans->meals->push_back(meal);
		}
		if(order != NULL) {
			for(Meal* &meal : *(order->getMeals())) {
				ans->meals->push_back(meal);
			}
		}
		return ans;
	}
	
	float getBill() {
		float bill = 0;
		for(int i = 0; i < meals->size(); i++) {
			bill += (*meals)[i]->getPrice();
		}
		return bill;
	}
};

class Party {
private:
		int size;
	
public:
	Party(int size) {
		this->size = size;
	}
	
	int getSize() {
		return this->size;
	}
};

class Table {
private:
	int capacity;
	bool available;
	Order *order;
	
public:
	
	Table(int capacity) {
		this->capacity = capacity;
		available =true;
		order = NULL;
	}
	
	int getCapacity() {
		return this->capacity;
	}
	
	bool isAvailable() {
		return this->available;
	}
	
	void markAvailable() {
		this->available = true;
	}
	
	void markUnavailable() {
		this->available = false;
	}
	
	Order * getCurrentOrder() {
		return this->order;
	}
	
	void setOrder(Order *o) {
		if(order == NULL) {
			this->order = o;
		}
		else {
			if( o != NULL) {
				this->order = this->order->mergeOrder(o);
			}
			else {
				this->order = o;
			}
		}
	}
};

class Restaurant {
private:
	vector<Table *> *tables;
	vector<Meal *> *menu;
	
public:
	Restaurant() {
		tables = new vector<Table *>;
		menu = new vector<Meal *>;
	}
	
	void findTable(Party *p) {
		for(Table* &t: *tables) {
			if(t->isAvailable()) {
				if(t->getCapacity() >= p->getSize()) {
					t->markUnavailable();
					return;
				}
			}
		}
	}
	
	void takeOrder(Table *t,Order *o) {
		t->setOrder(o);
	}
	
	float checkOut(Table *t) {
		float bill = 0;
		if(t->getCurrentOrder() != NULL) {
			bill = t->getCurrentOrder()->getBill();
		}
		t->markAvailable();
		t->setOrder(NULL);
		return bill;
	}
	
	vector<Meal *>* getMenu() {
		return menu;
	}
	
	void addTable(Table *t) {
		vector<Table *>::iterator it;
		for(it = tables->begin(); it!=tables->end(); it++) {
			if((*it)->getCapacity() > t->getCapacity()) {
				tables->insert(it,t);
				return;
			}
		}
		tables->push_back(t);
	}
	
	string to_string(int x) {
		string ans;
		stringstream st;
		st << x;
		st >> ans;
		return ans;
	}
	
	string restaurantDescription() {
		string description = "";
		for(int i = 0; i < tables->size(); i++) {
			Table* table = (*tables)[i];
			description += "Table: " + to_string(i) + ", table size: " 
			+ to_string(table->getCapacity()) + ", isAvailable: " +(table->isAvailable()?"true":"false") + ".";
			if(table->getCurrentOrder() == NULL)
				description += " No current order for this table";
			else 
			{
				description +=  " Order price: " + to_string(table->getCurrentOrder()->getBill())+".0";
			}
			description += ".\n";
		}
		description += "*****************************************\n";
		return description;
	}
	
};
