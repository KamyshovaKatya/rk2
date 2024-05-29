#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Prototype.cpp"

TEST(PrototypeTest, CloneConcretePrototype1) {
    // Arrange
    ConcretePrototype1 original(10);
    
    // Act
    ConcretePrototype1* clone = original.clone();
    
    // Assert
    ASSERT_NE(clone, &original); // Verify that the clone is a different object
    EXPECT_EQ(clone->_a, 10); // Verify that the clone has the correct value
    delete clone;
}

TEST(PrototypeTest, CloneConcretePrototype2) {
    // Arrange
    ConcretePrototype2 original(20);
    
    // Act
    ConcretePrototype2* clone = original.clone();
    
    // Assert
    ASSERT_NE(clone, &original); // Verify that the clone is a different object
    EXPECT_EQ(clone->_a, 20); // Verify that the clone has the correct value
    delete clone;
}

TEST(PrototypeTest, CloneConcretePrototype3) {
    // Arrange
    ConcretePrototype2 original(10);
    
    // Act
    ConcretePrototype2* clone = original.clone();
    
    // Assert
    ASSERT_NE(clone, &original); // Verify that the clone is a different object
    EXPECT_EQ(clone->_a, 10); // Verify that the clone has the correct value
    delete clone;
}
