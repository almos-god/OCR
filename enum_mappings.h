#ifndef ENUM_MAPPINGS_H
#define ENUM_MAPPINGS_H

#include <QHash>
#include <QString>

// Function enum
enum all_my_function {
    func_painting, func_size, func_color_extractor, func_my_erase, func_fill, func_crop, func_expansion, func_right_rotation, func_left_rotation, func_flip_vertically, func_flip_horizontally
};

// Graphics enum
enum all_my_graphics {
    basic, straight_line, right_circle, ellipse, isosceles_triangle, right_triangle, right_rectangle,
    rounded_rectangle, diamond, hexagon, four_pointed_star, five_pointed_star, six_pointed_star,
    lightning, left, right, top, bottom, rounded_rectangle_annotation, cloud_annotation, circle_annotation
};

// Global mappings from enum to string
static const QHash<all_my_function, QString> functionEnumToStringMap = {
    {func_painting, "painting"},
    {func_size, "size"},
    {func_color_extractor, "color_extractor"},
    {func_my_erase, "my_erase"},
    {func_fill, "fill"},
    {func_crop, "crop"},
    {func_expansion, "expansion"},
    {func_right_rotation, "right_rotation"},
    {func_left_rotation, "left_rotation"},
    {func_flip_vertically, "flip_vertically"},
    {func_flip_horizontally, "flip_horizontally"}
};

static const QHash<all_my_graphics, QString> graphicsEnumToStringMap = {
    {basic, "basic"},
    {straight_line, "straight_line"},
    {right_circle, "right_circle"},
    {ellipse, "ellipse"},
    {isosceles_triangle, "isosceles_triangle"},
    {right_triangle, "right_triangle"},
    {right_rectangle, "right_rectangle"},
    {rounded_rectangle, "rounded_rectangle"},
    {diamond, "diamond"},
    {hexagon, "hexagon"},
    {four_pointed_star, "four_pointed_star"},
    {five_pointed_star, "five_pointed_star"},
    {six_pointed_star, "six_pointed_star"},
    {lightning, "lightning"},
    {left, "left"},
    {right, "right"},
    {top, "top"},
    {bottom, "bottom"},
    {rounded_rectangle_annotation, "rounded_rectangle_annotation"},
    {cloud_annotation, "cloud_annotation"},
    {circle_annotation, "circle_annotation"}
};

// Global mappings from string to enum
static const QHash<QString, all_my_function> functionStringToEnumMap = {
    {"painting", func_painting},
    {"size", func_size},
    {"color_extractor", func_color_extractor},
    {"my_erase", func_my_erase},
    {"fill", func_fill},
    {"crop", func_crop},
    {"expansion", func_expansion},
    {"right_rotation", func_right_rotation},
    {"left_rotation", func_left_rotation},
    {"flip_vertically", func_flip_vertically},
    {"flip_horizontally", func_flip_horizontally}
};

static const QHash<QString, all_my_graphics> graphicsStringToEnumMap = {
    {"basic", basic},
    {"straight_line", straight_line},
    {"right_circle", right_circle},
    {"ellipse", ellipse},
    {"isosceles_triangle", isosceles_triangle},
    {"right_triangle", right_triangle},
    {"right_rectangle", right_rectangle},
    {"rounded_rectangle", rounded_rectangle},
    {"diamond", diamond},
    {"hexagon", hexagon},
    {"four_pointed_star", four_pointed_star},
    {"five_pointed_star", five_pointed_star},
    {"six_pointed_star", six_pointed_star},
    {"lightning", lightning},
    {"left", left},
    {"right", right},
    {"top", top},
    {"bottom", bottom},
    {"rounded_rectangle_annotation", rounded_rectangle_annotation},
    {"cloud_annotation", cloud_annotation},
    {"circle_annotation", circle_annotation}
};

#endif // ENUM_MAPPINGS_H
