#include <iostream>
#include <cstring>

using namespace std;

typedef struct DqNode {
	int data;
	DqNode *left;
	DqNode *right;
}DqNode;

class Deque {
private:
	int size;
	DqNode *head;
	DqNode *tail;
public:
	Deque();
	bool is_empty();
	DqNode *create_node(int _data, DqNode *left, DqNode *right);
	void push_front(int _data);
	void push_back(int _data);
	int pop_front();
	int pop_back();

	int getFrontData() {
		if (is_empty()) {
			return -1;
		}
		return this->head->data;
	}
	int getBackData() {
		if (is_empty()) {
			return -1;
		}
		return this->tail->data;
	}
	int getSize() {
		return this->size;
	}

};

Deque::Deque() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

bool Deque::is_empty() {
	if (this->head == NULL) return true;
	return false;
}

DqNode *Deque::create_node(int _data, DqNode *left, DqNode *right) {
	DqNode *node = new DqNode();
	node->data = _data;
	node->left = left;
	node->right = right;

	return node;
}
void Deque::push_front(int _data) {
	DqNode *tmpNode = create_node(_data, nullptr, this->head); // 맨앞에있던게 이제 뒤로 밀려날 시간..
	
	if (this->is_empty()) { // 비어있으면 꼬리도 node 주소를
		tail = tmpNode;
		head = tmpNode;
	} else {
		head->left = tmpNode; // 이게 먼저돼야 길을 안잃음.
		head = tmpNode;
	}
	size++;
}

void Deque::push_back(int _data) {
	DqNode *tmpNode = create_node(_data, this->tail, nullptr); // 맨앞에있던게 이제 뒤로 밀려날 시간..

	if (this->is_empty()) { // 비어있으면 꼬리도 node 주소를
		tail = tmpNode;
		head = tmpNode;
	} else {
		tail->right= tmpNode; // 이게 먼저돼야 길을 안잃음.
		tail = tmpNode;
	}
	size++;
}
int Deque::pop_front() {
	if (this->is_empty()) {
		return -1;
	}

	DqNode *needToDel = head;
	int tmp = needToDel->data;
	head = head->right;
	if (head != nullptr) {
		head->left = nullptr;
	} else {
		tail = nullptr;
	}

	delete needToDel;

	size--;
	return tmp;
}
int Deque::pop_back() {
	if (this->is_empty()) {
		return -1;
	}

	DqNode *needToDel = tail;
	int tmp = needToDel->data;
	tail = tail->left;
	if (tail != nullptr) {
		tail->right = nullptr;
	} else {
		head = nullptr;
	}

	delete needToDel;

	size--;
	return tmp;
}



int main(void) {

	Deque *dq = new Deque();

	int commCount;
	scanf("%d", &commCount);

	char comm[11];
	int tmp;

	for (int i = 0; i < commCount; i++) {
		scanf("%s", comm);
		if (strcmp(comm,"push_front") == 0) {
			scanf("%d", &tmp);
			dq->push_front(tmp);
		} else if (strcmp(comm,"push_back") == 0) {
			scanf("%d", &tmp);
			dq->push_back(tmp);
		} else if (strcmp(comm,"pop_front") == 0) {
			printf("%d\n", dq->pop_front());
		} else if (strcmp(comm,"pop_back") == 0) {
			printf("%d\n", dq->pop_back());
		} else if (strcmp(comm,"size") == 0) {
			printf("%d\n", dq->getSize());
		} else if (strcmp(comm,"empty") == 0) {
			printf("%d\n", dq->is_empty());
		} else if (strcmp(comm,"front") == 0) {
			printf("%d\n", dq->getFrontData());
		} else if (strcmp(comm,"back") == 0) {
			printf("%d\n", dq->getBackData());
		}
	}

	return 0;
}