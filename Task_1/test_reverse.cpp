#include <gtest/gtest.h>

void reverse(double *a, int i, int j);

TEST(Task1Test, ReverseTest) {
    double arr1[4] {1, 2, 3, 4};
    double arr2[4] {4, 3, 2, 1};
    reverse(arr1, 0, 3);
    for (int i = 0; i <= 3; i++) {
        ASSERT_EQ(arr1[i], arr2[i]);
    }
}

int main(int argc, char **argv)
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }

void reverse(double *a, int i, int j) {
    while (i < j) {
        int rev = a[i]; 
        a[i] = a[j];
        a[j] = rev;
        i++;
        j--;
    }
}