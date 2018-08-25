#pragma once
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

class Panel {
private:
	static stack<Panel *> panelStack; //通过栈来管理ui
public:
	/*
		将要显示的界面添加到栈
	*/
	static void addPanel(Panel *p) {
		panelStack.push(p);
	}

	/*
		显示栈顶元素
	*/
	static void show() {
		if (panelStack.empty())
			throw string("UI Stack is empty");
		Panel* p = panelStack.top();
		p->showPanel();
	}

	/*
		弹出栈顶元素
	*/
	static void removePanel() {
		panelStack.pop();
	}
protected:
	virtual void showPanel() {};
};