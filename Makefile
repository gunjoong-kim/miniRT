NAME			=	minirt
CC				=	cc
CFLAG			=	#-Wall -Wextra -Werror
RM				=	rm -f

LIBFT_DIR		=	libft/
LIBFT			=	libft.a
LIBFT_LINK		=	-L$(LIBFT_DIR) -lft

MLX_DIR			=	mlx/
MLX				=	libmlx.dylib
MLX_LINK		=	-Lmlx -lmlx -framework OpenGL -framework Appkit

INC				=	-Imandatory/inc/ -Ibonus/inc/ -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS_M			=	mandatory/src/main.c							\
					mandatory/src/utils/utils_1.c					\
					mandatory/src/utils/utils_2.c					\
					mandatory/src/utils/utils_3.c					\
					mandatory/src/utils/mlx_utils.c					\
					mandatory/src/utils/memory_free.c				\
					mandatory/src/vec3/vec3_1.c						\
					mandatory/src/vec3/vec3_2.c						\
					mandatory/src/vec3/vec3_3.c						\
					mandatory/src/vec3/vec3_4.c						\
					mandatory/src/parser/parser_1.c					\
					mandatory/src/parser/parser_2.c					\
					mandatory/src/parser/parser_3.c					\
					mandatory/src/parser/parser_util_1.c			\
					mandatory/src/parser/parser_util_2.c			\
					mandatory/src/parser/constructor.c				\
					mandatory/src/bvh/bvh.c							\
					mandatory/src/bvh/comparator.c					\
					mandatory/src/bvh/bvh_utils.c					\
					mandatory/src/object/aabb.c						\
					mandatory/src/object/sphere.c					\
					mandatory/src/object/plane.c					\
					mandatory/src/object/cylinder.c					\
					mandatory/src/object/object_utils.c				\
					mandatory/src/texture/color.c					\
					mandatory/src/material/emit.c					\
					mandatory/src/material/scatter.c				\
					mandatory/src/render/phong.c					\
					mandatory/src/render/render.c 					\
					mandatory/src/camera.c							\
					mandatory/src/ray.c								\

SRCS_B			=	bonus/src/main_bonus.c									\
					bonus/src/utils/utils_1_bonus.c							\
					bonus/src/utils/utils_2_bonus.c							\
					bonus/src/utils/err_utils_bonus.c						\
					bonus/src/utils/mlx_utils_bonus.c						\
					bonus/src/vec3/vec3_1_bonus.c							\
					bonus/src/vec3/vec3_2_bonus.c							\
					bonus/src/vec3/vec3_3_bonus.c							\
					bonus/src/vec3/vec3_4_bonus.c							\
					bonus/src/vec3/vec3_5_bonus.c							\
					bonus/src/parser/constructor_bonus.c					\
					bonus/src/parser/init_hittable_bonus.c					\
					bonus/src/parser/init_camera_bonus.c 					\
					bonus/src/parser/init_world_bonus.c						\
					bonus/src/parser/init_mat_bonus.c						\
					bonus/src/parser/init_obj_1_bonus.c						\
					bonus/src/parser/init_obj_2_bonus.c						\
					bonus/src/parser/init_tex_bonus.c 						\
					bonus/src/parser/parser_minirt_bonus.c					\
					bonus/src/parser/parser_util1_bonus.c					\
					bonus/src/parser/parser_util2_bonus.c					\
					bonus/src/bvh/bvh_bonus.c								\
					bonus/src/bvh/comparator_bonus.c						\
					bonus/src/bvh/bvh_utils_bonus.c							\
					bonus/src/object/aabb_bonus.c							\
					bonus/src/object/sphere_bonus.c							\
					bonus/src/object/plane_bonus.c							\
					bonus/src/object/cylinder_bonus.c						\
					bonus/src/object/cone_bonus.c							\
					bonus/src/object/object_utils_bonus.c					\
					bonus/src/object/get_uv_bonus.c 						\
					bonus/src/texture/color_bonus.c							\
					bonus/src/material/emit_bonus.c							\
					bonus/src/material/scatter_bonus.c						\
					bonus/src/render/phong_bonus.c							\
					bonus/src/render/path_bonus.c							\
					bonus/src/render/render_bonus.c 						\
					bonus/src/render/ray_bonus.c							\
					bonus/src/render/aa_bonus.c								\
					bonus/src/thread/thread_bonus.c							\

OBJS_M			=	$(SRCS_M:.c=.o)
OBJS_B			=	$(SRCS_B:.c=.o)

BONUS_MODE = $(findstring $(MAKECMDGOALS),bonus)

ifeq ($(BONUS_MODE), )
    OBJS = $(OBJS_M)
else
    OBJS = $(OBJS_B)
endif

all: $(NAME)

bonus: $(NAME)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	$(CC) $(CFLAG) $(INC) $(OBJS) $(LIBFT_LINK) $(MLX_LINK) -o $(NAME)
	install_name_tool -change $(MLX) $(MLX_DIR)$(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAG) $(INC) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all bonus clean fclean re