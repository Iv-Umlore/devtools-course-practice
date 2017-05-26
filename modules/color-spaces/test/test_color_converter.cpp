// Copyright 2017 Baranov Evgeny

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/ColorConverter.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ColorConverterApplicationTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); i++) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    ColorConverter app_;
    std::string output_;
};

TEST_F(ColorConverterApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a color converter application");
}

TEST_F(ColorConverterApplicationTest, Not_Five_Arguments) {
    vector<string> args = { "1" };

    Act(args);

    Assert("ERROR: Should be 5 arguments.");
}

TEST_F(ColorConverterApplicationTest, Wrong_Convert_Type) {
    vector<string> args = { "1", "2", "3", "asd", "asd" };

    Act(args);

    Assert("Wrong type");
}

TEST_F(ColorConverterApplicationTest, Wrong_Hue_HSVHSB) {
    vector<string> args = { "400", "2", "3", "HSV", "RGB" };

    Act(args);

    Assert("The index of hue not in the range 0-360");
}

TEST_F(ColorConverterApplicationTest, Wrong_Saturation_HSVHSB) {
    vector<string> args = { "1", "400", "3", "HSV", "RGB" };

    Act(args);

    Assert("The index of saturation not in the range 0-100");
}

TEST_F(ColorConverterApplicationTest, Wrong_Brightnes_HSVHSB) {
    vector<string> args = { "1", "2", "400", "HSV", "RGB" };

    Act(args);

    Assert("The index of brightnes not in the range 0-100");
}

TEST_F(ColorConverterApplicationTest, Wrong_Lightness_LAB) {
    vector<string> args = { "400", "2", "3", "LAB", "RGB" };

    Act(args);

    Assert("The index of lightness isn't in the range 0-100");
}

TEST_F(ColorConverterApplicationTest, Wrong_A_Color_LAB) {
    vector<string> args = { "1", "400", "3", "HSV", "RGB" };

    Act(args);

    Assert("The index of a color isn't in the range 0-128");
}

TEST_F(ColorConverterApplicationTest, Wrong_B_Color_LAB) {
    vector<string> args = { "1", "2", "400", "HSV", "RGB" };

    Act(args);

    Assert("The index of b color isn't in the range 0-128");
}

TEST_F(ColorConverterApplicationTest, Wrong_R_RGB) {
    vector<string> args = { "400", "2", "3", "RGB", "HSV" };

    Act(args);

    Assert("The index of red color isn't in the range 0-255");
}

TEST_F(ColorConverterApplicationTest, Wrong_G_RGB) {
    vector<string> args = { "1", "400", "3", "RGB", "HSV" };

    Act(args);

    Assert("The index of green color isn't in the range 0-255");
}

TEST_F(ColorConverterApplicationTest, Wrong_B_RGB) {
    vector<string> args = { "1", "2", "400", "RGB", "HSV" };

    Act(args);

    Assert("The index of blue color isn't in the range 0-255");
}

TEST_F(ColorConverterApplicationTest, Wrong_X_XYZ) {
    vector<string> args = { "400", "2", "3", "XYZ", "RGB" };

    Act(args);

    Assert("The index of x isn't in the range 0-95");
}

TEST_F(ColorConverterApplicationTest, Wrong_Y_XYZ) {
    vector<string> args = { "1", "400", "3", "XYZ", "RGB" };

    Act(args);

    Assert("The index of y isn't in the range 0-100");
}

TEST_F(ColorConverterApplicationTest, Wrong_Z_XYZ) {
    vector<string> args = { "1", "2", "400", "XYZ", "RGB" };

    Act(args);

    Assert("The index of z isn't in the range 0-108");
}
