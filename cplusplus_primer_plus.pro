TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    mystack.hpp \
    member_template.hpp \
    template_parameter.hpp \
    no_template_friend_function.hpp \
    bound_template_friend.hpp \
    unbound_template_friend.hpp \
    exception_class_throw.hpp \
    rtti_test.hpp \
    smart_ptr.hpp \
    stl_test.hpp \
    c_plus_11.hpp
