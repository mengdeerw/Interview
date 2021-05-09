/*

题目：设计餐馆 II

不能订外卖

能预订座位

MAX_DINETIME 为 2， 意为占用一桌吃饭的最大时长为2小时

如果餐桌被预定，则无法入座

餐馆的桌子有不同大小

餐馆会优先选择适合当前Party最小的空桌（例如，如果当事人有3人，餐厅会安排4人桌，而不是10人桌）

相对设计餐馆 I，Table新增functions 需要实现。相关函数之后会调用restaurantDescription, 来验证你的程序是否正确。

样例
meal(10.0)
meal(13.0)
meal(15.0)
table(1, 4)
table(2, 10)
party(3)
reservedDate(6) // Date(2013年1月4日 + 6 * Restaurant.HOUR);
party(7)
reservedDate(7) // Date(2013年1月4日 + 7 * Restaurant.HOUR);
order(1)
order(2, 3)
findTableForReservation(1, 1) // 第一个的参数是party的id，第二个参数是reservedDate的id
findTableForReservation(2, 2) 
Table: 1, table size: 4, isAvailable: true. No current order for this table. Current reservation dates for this table are: 4 Jan 2013 06:00:00 GMT ; .
Table: 2, table size: 10, isAvailable: true. No current order for this table. Current reservation dates for this table are: .
*****************************************

Table: 1, table size: 4, isAvailable: true. No current order for this table. Current reservation dates for this table are: 4 Jan 2013 06:00:00 GMT ; .
Table: 2, table size: 10, isAvailable: true. No current order for this table. Current reservation dates for this table are: 4 Jan 2013 07:00:00 GMT ; .
*****************************************
*/
class Meal
{
private: 
	float price;

public:
	Meal(float price)
	{
		this->price = price;
	}

	float getPrice()
	{
		return this->price;
	}
};

class Order
{
private:
	vector<Meal *> *meals;

public:
	Order()
	{
		meals = new vector<Meal *>;
	}

	vector<Meal *>* getMeals()
	{
		return meals;
	}

	void mergeOrder(Order *order)
	{
		if (order != NULL)
		{
			for (Meal * meal :(*order->getMeals()))
			{
				meals->push_back(meal);
			}
		}
	}

	float getBill()
	{
		float bill = 0;
		for (Meal * meal : (*meals))
		{
			bill += meal->getPrice();
		}
		return bill;
	}
};

class Party
{
private:
	int size;

public:
	Party(int size)
	{
		this->size = size;
	}

	int getSize()
	{
		return this->size;
	}
};

class Table
{
private:
	int id;
	int capacity;
	bool available;
	Order *order;
	vector<Date *> *reservations;

	int findDatePosition(Date *d)
	{
		int len = reservations->size();
		if (len == 0)
		{
			return 0;
		}
		if (d->getTime() > (*reservations)[len - 1]->getTime())
		{
			return len;
		}

		int i = 0;
		int j = len;
		while (i < j)
		{
			int m = (i + j) / 2;
			if (d->getTime() > (*reservations)[m]->getTime())
			{
				i = m + 1;
			}
			else
			{
				j = m;
			}
		}
		return j;
	}

public:
	Table(int id, int capacity)
	{
		this->id = id;
		this->capacity = capacity;
		available = true;
		order = NULL;
		reservations = new vector<Date *>;
	}

	int getId()
	{
		return this->id;
	}

	int getCapacity()
	{
		return this->capacity;
	}

	vector<Date *> *getReservation()
	{
		return reservations;
	}

	bool isAvailable()
	{
		return this->available;
	}

	void markAvailable()
	{
		this->available = true;
	}

	void markUnavailable()
	{
		this->available = false;
	}

	Order *getCurrentOrder()
	{
		return this->order;
	}

	void setOrder(Order *o)
	{
		if (order == NULL)
		{
			this->order = o;
		}
		else
		{
			if(o != NULL)
			{
				this->order->mergeOrder(o);
			}
		}
	}

	bool noFollowReservation(Date *d)
	{
		static int MILLI_TO_HOUR = 1000 * 60 * 60;
		int position = findDatePosition(d);

		if (position < reservations->size())
		{
			Date *nextReservation = (*reservations)[position];
			int diff = nextReservation->getTime() - d->getTime();
			if (diff < MAX_DINEHOUR)
			{
				return false;
			}
		}
		return true;
	}

	bool reserveForDate(Date *d)
	{
		static int MILLI_TO_HOUR = 1000 * 60 * 60;
		int position = findDatePosition(d);
		int before = position - 1;
		int after = position;

		if (before >= 0)
		{
			Date *previousReservation = (*reservations)[before];
			int diff = d->getTime() - previousReservation->getTime();
			if (diff < MAX_DINEHOUR)
			{
				return false;
			}
		}

		if (after < reservations->size())
		{
			Date *nextReservation = (*reservations)[after];
			int diff = nextReservation->getTime() - d->getTime();
			if (diff < MAX_DINEHOUR)
			{
				return false;
			}
		}
		reservations->insert(reservations->begin() + position, d);
		return true;
	}

	void removeReservation(Date *d)
	{
		vector<Date *>::iterator it;
		for (it = reservations->begin(); it != reservations->end(); it++)
		{
			if (*it == d)
			{
				reservations->erase(it);
				break;
			}
		}
	}
};

class Reservation
{
private:
	Table *table;
	Date *date;

public:
	Reservation(Table *table, Date *date)
	{
		this->table = table;
		this->date = date;
	}

	Date *getDate()
	{
		return date;
	}

	Table *getTable()
	{
		return table;
	}
};

class Restaurant
{
private:
	vector<Table *> *tables;
	vector<Meal *> *menu;
public:
	

	Restaurant()
	{
		tables = new vector<Table *>;
		menu = new vector<Meal *>;
	}

	void findTable(Party *p)
	{
		Date *currentDate = new Date();
		for (Table *t : (*tables))
		{
			if (t->isAvailable())
			{
				if (t->getCapacity() >= p->getSize())
				{
					if (t->noFollowReservation(currentDate))
					{
						t->markUnavailable();
						return;
					}
				}
			}
		}
	}

	void takeOrder(Table *t, Order *o)
	{
		t->setOrder(o);
	}

	float checkOut(Table *t)
	{
		float bill = 0;
		if (t->getCurrentOrder() != NULL)
		{
			bill = t->getCurrentOrder()->getBill();
		}
		t->markAvailable();
		t->setOrder(NULL);

		return bill;
	}

	vector<Meal *> *getMenu()
	{
		return menu;
	}

	static bool cmp(Table* &a, Table* &b)
	{
		return a->getCapacity() < b->getCapacity();
	}

	void addTable(Table *t)
	{
		tables->push_back(t);
		sort(tables->begin(), tables->end(),cmp);
	}

	Reservation *findTableForReservation(Party *p, Date *date)
	{
		for (Table *table : (*tables))
		{
			if (table->getCapacity() >= p->getSize())
			{
				if (table->reserveForDate(date))
				{
					return new Reservation(table, date);
				}
				
			}
		}
		return NULL;
	}

	void cancelReservation(Reservation *r)
	{
		Date *date = r->getDate();
		r->getTable()->removeReservation(date);
	}

	void redeemReservation(Reservation *r)
	{
		Date *date = r->getDate();
		Table *table = r->getTable();

		table->markUnavailable();
		table->removeReservation(date);
	}

	string restaurantDescription()
	{
		string description = "";
		for (int i = 0; i < tables->size(); i++)
		{
			Table *table = (*tables)[i];
			description += "Table: " + to_string(table->getId()) + ", table size: " + to_string(table->getCapacity()) +
				", isAvailable: " + (table->isAvailable() ? "true" : "false") + ".";
			if (table->getCurrentOrder() == NULL)
			{
				description+= " No current order for this table";
			}
			else
			{
				description += " Order price: ";
				string str = to_string(table->getCurrentOrder()->getBill());
				description+=str.substr(0, str.size() - 5);
			}
			description += ". Current reservation dates for this table are: ";

			for (Date *date : (*table->getReservation()))
			{
				description += date->toGMTString() + " ; ";
			}

			description += ".\n";
		}
		description += "*****************************************\n";
		return description;
	}
};
