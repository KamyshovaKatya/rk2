#include <gtest/gtest.h>
#include <gmock/gmock.h>

enum Type {
    Concrete1 = 0,
    Concrete2 = 1
};

class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void print() = 0;
};

class ConcretePrototype1 : public Prototype {
public:
    int _a;
    void print() {
        std::cout << "concrete 1: " << _a << std::endl;
    }
    ConcretePrototype1() {}
    ConcretePrototype1(int a) : _a(a) {}
    ConcretePrototype1* clone() {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype {
public:
    int _a;
    void print() {
        std::cout << "concrete 2: " << _a << std::endl;
    }
    ConcretePrototype2() {}
    ConcretePrototype2(int a) : _a(a) {}
    ConcretePrototype2* clone() {
        return new ConcretePrototype2(*this);
    }
};

class PrototypeCreator {
    std::map<Type, Prototype*> _protoList;
public:
    PrototypeCreator() {
        _protoList[Type::Concrete1] = new ConcretePrototype1(12);
        _protoList[Type::Concrete2] = new ConcretePrototype2(23);
    }
    Prototype* createPrototype(Type t) {
        return _protoList[t]->clone();
    }
};

// Тест для ConcretePrototype1
TEST(ConcretePrototype1Test, CloneTest) {
    ConcretePrototype1 prototype1(10);
    Prototype* clonedPrototype = prototype1.clone();
    ConcretePrototype1* concreteCloned = dynamic_cast<ConcretePrototype1*>(clonedPrototype);
    ASSERT_NE(concreteCloned, nullptr);
    EXPECT_EQ(concreteCloned->_a, 10);
    delete clonedPrototype;
}

// Тест для ConcretePrototype2
TEST(ConcretePrototype2Test, CloneTest) {
    ConcretePrototype2 prototype2(20);
    Prototype* clonedPrototype = prototype2.clone();
    ConcretePrototype2* concreteCloned = dynamic_cast<ConcretePrototype2*>(clonedPrototype);
    ASSERT_NE(concreteCloned, nullptr);
    EXPECT_EQ(concreteCloned->_a, 20);
    delete clonedPrototype;
}

// Тест для PrototypeCreator
TEST(PrototypeCreatorTest, CreatePrototypeTest) {
    PrototypeCreator creator;
    Prototype* prototype1 = creator.createPrototype(Type::Concrete1);
    ConcretePrototype1* concretePrototype1 = dynamic_cast<ConcretePrototype1*>(prototype1);
    ASSERT_NE(concretePrototype1, nullptr);
    EXPECT_EQ(concretePrototype1->_a, 12);

    Prototype* prototype2 = creator.createPrototype(Type::Concrete2);
    ConcretePrototype2* concretePrototype2 = dynamic_cast<ConcretePrototype2*>(prototype2);
    ASSERT_NE(concretePrototype2, nullptr);
    EXPECT_EQ(concretePrototype2->_a, 23);

    delete prototype1;
    delete prototype2;
}

