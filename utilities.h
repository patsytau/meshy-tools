typedef struct { float x, y, z; } vector;
typedef struct { float r, g, b; } colour;

typedef struct{ vector centre, norm; } fc_normal;

typedef struct{
	unsigned short sides;
	long int *verts;
} face;

/* a vertex augmented with normal information and associated face data */
typedef struct{
	int assoc_faces;
	long int *faces;
} vert_extra;

struct OFF
{
	vector *vertices;
	vector *vert_normals;
	vert_extra *vert_aug;

	face *faces;
	fc_normal *face_normals;

	colour *colours;

	int has_colours;
	int has_normals;

	unsigned long numverts;
	unsigned long numfaces;
	unsigned long numedges;
};

void read_OFF_data(FILE *infile, struct OFF *mesh);

void analyse_mesh(struct OFF *mesh, unsigned short idx);

void initialise_mesh(struct OFF *mesh);

void free_mesh(struct OFF *mesh);

void open_file(FILE **fp
		, char *filename
		, char *mode);

void read_off_header(FILE * infile, struct OFF *mesh);

void read_vertex_data(FILE * infile, struct OFF *mesh);

void read_face_data( FILE * infile, struct OFF *mesh);

void write_off_file( FILE * outfile
	, vector * vertices
	, vector * normals
	, face * faces
	, colour * colours
	, unsigned long numverts
	, unsigned long numfaces
	, unsigned long numedges
	, int has_normals
	, int has_colour );

