#ifndef RENDERER_H
#define RENDERER_H

#include "../util/util.h"
#include "gfx.h"
#include "vao.h"
#include "vbo.h"

enum FillMode {
    FILL_MODE_FILL, FILL_MODE_LINE
};

#define TEXTURE_LAST TEXTURE_HOTBAR
enum Textures {
    TEXTURE_BKG,
    TEXTURE_BOTTOM_BAR,
    TEXTURE_TOP_BAR
};

#define CAMERA_STACK_MAX 256

enum RenderPass {
    PASS_2D
};

struct Renderer {


    struct Texture textures[TEXTURE_LAST + 1];

    struct BlockAtlas block_atlas;

    vec4s clear_color;

    struct VBO vbo, ibo;
    struct VAO vao;

    struct {
        bool wireframe : 1;
    } flags;
};

void renderer_init(struct Renderer *self);
void renderer_destroy(struct Renderer *self);
void renderer_update(struct Renderer *self);
void renderer_prepare(struct Renderer *self, enum RenderPass pass);
void renderer_set_camera(struct Renderer *self, enum CameraType type);
void renderer_push_camera(struct Renderer *self);
void renderer_pop_camera(struct Renderer *self);
void renderer_set_view_proj(struct Renderer *self);

void renderer_quad_color(
    struct Renderer *self, vec2s size,
    vec4s color, mat4s model);

void renderer_quad_texture(
    struct Renderer *self, struct Texture texture,
    vec2s size, vec4s color,
    vec2s uv_min, vec2s uv_max,
    mat4s model);

void renderer_aabb(
    struct Renderer *self, AABB aabb, vec4s color,
    mat4s model, enum FillMode fill_mode);

#endif