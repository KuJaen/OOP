//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::shared_mut(const shared_mut& mut) {
	if (mut._mgr) {
		int val = mut._mgr->ptr->get();
		this->_mgr = mut._mgr;
	}
	increase();
}

shared_mut::~shared_mut() {
    release();
}

void shared_mut::increase() {
	this->_mgr->count++;
}

void shared_mut::release() {
	this->_mgr->count--;
	if(this->_mgr->count == 0)
		_mgr->~mgr();
	else {
		_mgr = new mgr();
	}
}

Object* shared_mut::get() const{
	return this->_mgr->ptr;
}

int shared_mut::count() {
	return this->_mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut& shared) {
	int var = this->_mgr->ptr->get() + shared.get()->get();
	return shared_mut(new Object(var));
}
shared_mut shared_mut::operator-(const shared_mut& shared) {
	int var = this->_mgr->ptr->get() - shared.get()->get();
	return shared_mut(new Object(var));
}
shared_mut shared_mut::operator*(const shared_mut& shared) {
	int var = this->_mgr->ptr->get() * shared.get()->get();
	return shared_mut(new Object(var));
}
shared_mut shared_mut::operator/(const shared_mut& shared) {
	int var = this->_mgr->ptr->get() / shared.get()->get();
	return shared_mut(new Object(var));
}
shared_mut& shared_mut::operator=(const shared_mut& r) {
	this->release();
	this->_mgr = r._mgr;
	this->increase();
	return *this;
}

Object* shared_mut::operator->() {
	return this->_mgr->ptr;
}
} // end of namespace ptr