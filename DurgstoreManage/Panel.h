#pragma once
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

class Panel {
private:
	static stack<Panel *> panelStack; //ͨ��ջ������ui
public:
	/*
		��Ҫ��ʾ�Ľ�����ӵ�ջ
	*/
	static void addPanel(Panel *p) {
		panelStack.push(p);
	}

	/*
		��ʾջ��Ԫ��
	*/
	static void show() {
		if (panelStack.empty())
			throw string("UI Stack is empty");
		Panel* p = panelStack.top();
		p->showPanel();
	}

	/*
		����ջ��Ԫ��
	*/
	static void removePanel() {
		panelStack.pop();
	}
protected:
	virtual void showPanel() {};
};