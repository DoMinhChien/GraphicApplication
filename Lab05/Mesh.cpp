#include "Mesh.h"
#include <iterator>

#define PI			3.1415926
#define	COLORNUM		14


float	ColorArr[COLORNUM][3] = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0},
								{1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0},
								 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9} };
void Mesh::CreateCube(float	fSize)

{
	int i;

	numVerts=8;
	pt = new Point3[numVerts];
	pt[0].set(-fSize, fSize, fSize);
	pt[1].set( fSize, fSize, fSize);
	pt[2].set( fSize, fSize, -fSize);
	pt[3].set(-fSize, fSize, -fSize);
	pt[4].set(-fSize, -fSize, fSize);
	pt[5].set( fSize, -fSize, fSize);
	pt[6].set( fSize, -fSize, -fSize);
	pt[7].set(-fSize, -fSize, -fSize);


	numFaces= 6;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 5;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;
	for(i = 0; i<face[0].nVerts ; i++)
		face[0].vert[i].colorIndex = 0;
	
	//Right face
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for(i = 0; i<face[1].nVerts ; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for(i = 0; i<face[2].nVerts ; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for(i = 0; i<face[3].nVerts ; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for(i = 0; i<face[4].nVerts ; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for(i = 0; i<face[5].nVerts ; i++)
		face[5].vert[i].colorIndex = 5;

}


void Mesh::CreateTetrahedron()
{
	int i;
	numVerts=4;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(1, 0, 0);
	pt[2].set(0, 1, 0);
	pt[3].set(0, 0, 1);

	numFaces= 4;
	face = new Face[numFaces];

	face[0].nVerts = 3;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 2;
	face[0].vert[2].vertIndex = 3;
	for(i = 0; i<face[0].nVerts ; i++)
		face[0].vert[i].colorIndex = 0;
	

	face[1].nVerts = 3;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;	
	face[1].vert[1].vertIndex = 2;
	face[1].vert[2].vertIndex = 1;
	for(i = 0; i<face[1].nVerts ; i++)
		face[1].vert[i].colorIndex = 1;

	
	face[2].nVerts = 3;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 3;
	face[2].vert[2].vertIndex = 2;
	for(i = 0; i<face[2].nVerts ; i++)
		face[2].vert[i].colorIndex = 2;


	face[3].nVerts = 3;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 3;
	face[3].vert[2].vertIndex = 0;
	for(i = 0; i<face[3].nVerts ; i++)
		face[3].vert[i].colorIndex = 3;
}


void Mesh::DrawWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}

void Mesh::DrawColor()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;
			int		ic = face[f].vert[v].colorIndex;

			ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]);
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}


void Mesh::CreateCylinder(int nSegment, float fHeight, float fRadius)
{
	int i;
	float x, y, z;
	float angle = 2 * PI / nSegment;

	numVerts = nSegment * 2 + 2;
	pt = new Point3[numVerts];
	numFaces = 3 * nSegment;
	face = new Face[numFaces];

	for (i = 0; i < nSegment; i++)
	{
		y = fHeight / 2;
		x = fRadius * cos(i * angle);
		z = fRadius * sin(i * angle);
		pt[i].set(x, y, z);
		int newY = -fHeight / 2;
		pt[i + nSegment].set(x, newY, z);
	}
	pt[2 * nSegment].set(0, fHeight / 2, 0);
	pt[2 * nSegment + 1].set(0, -fHeight / 2, 0);
	//Danh sach mat


	for (i = 0; i < nSegment; i++)
	{
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		face[i].vert[0].vertIndex = i;
		face[i].vert[1].vertIndex = i + nSegment;

		if (i == nSegment - 1)
		{
			face[i].vert[2].vertIndex = nSegment;
			face[i].vert[3].vertIndex = 0;
		}
		else
		{
			face[i].vert[2].vertIndex = i + nSegment + 1;
			face[i].vert[3].vertIndex = i + 1;
		}
			
		for (int j = 0; j < face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i % COLORNUM;
	}

	for (i = 0; i < nSegment; i++)
	{
		face[i + nSegment].nVerts = 3;
		face[i + nSegment].vert = new VertexID[face[i + nSegment].nVerts];

		face[i + nSegment].vert[0].vertIndex = nSegment * 2;
		face[i + nSegment].vert[1].vertIndex = i;
		if (i == nSegment - 1)
			face[i + nSegment].vert[2].vertIndex = 0;
		else
			face[i + nSegment].vert[2].vertIndex = i + 1;

		for (int j = 0; j < face[i + nSegment].nVerts; j++)
			face[i + nSegment].vert[j].colorIndex = i % COLORNUM;


		face[i + 2 * nSegment].nVerts = 3;
		face[i + 2 * nSegment].vert = new VertexID[face[i + 2 * nSegment].nVerts];

		face[i + 2 * nSegment].vert[0].vertIndex = nSegment * 2 + 1;
		face[i + 2 * nSegment].vert[1].vertIndex = i + nSegment;
		if (i == nSegment - 1)
			face[i + 2 * nSegment].vert[2].vertIndex = 0 + nSegment;
		else
			face[i + 2 * nSegment].vert[2].vertIndex = i + 1 + nSegment;

		for (int j = 0; j < face[i + 2 * nSegment].nVerts; j++)
			face[i + 2 * nSegment].vert[j].colorIndex = i % COLORNUM;
	}

}
void Mesh::CreateCylinderWithHole(int nSegment, float fHeight, float fORadius, float fIRadius)
{
	int i;
	float x, y, z;
	float angle = 2 * PI / nSegment;

	numVerts = 4 * nSegment;

	pt = new Point3[numVerts];

	for (i = 0; i < nSegment; i++)
	{
		y = fHeight / 2;
		x = fORadius * cos(i * angle);
		z = fORadius * sin(i * angle);
		pt[i].set(x, y, z);

		y = fHeight / 2;
		x = fIRadius * cos(i * angle) / 2;
		z = fIRadius * sin(i * angle) / 2;
		pt[i + nSegment * 2].set(x, y, z);
	}

	for (i = 0; i < nSegment; i++)
	{
		y = -fHeight / 2;
		x = fORadius * cos(i * angle);
		z = fORadius * sin(i * angle);
		pt[i + nSegment].set(x, y, z);

		y = -fHeight / 2;
		x = fIRadius * cos(i * angle) / 2;
		z = fIRadius * sin(i * angle) / 2;
		pt[i + nSegment * 3].set(x, y, z);


	}
	numFaces = 4 * nSegment;
	face = new Face[numFaces];


	for (i = 0; i < nSegment; i++)
	{
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		face[i].vert[0].vertIndex = i;
		face[i].vert[1].vertIndex = i + nSegment;

		if (i == nSegment - 1)
			face[i].vert[2].vertIndex = nSegment;
		else
			face[i].vert[2].vertIndex = i + nSegment + 1;

		if (i == nSegment - 1)
			face[i].vert[3].vertIndex = 0;
		else
			face[i].vert[3].vertIndex = i + 1;
		for (int j = 0; j < face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i % COLORNUM;
	}
	for (i = 0; i < nSegment; i++)
	{
		face[i + nSegment].nVerts = 4;
		face[i + nSegment].vert = new VertexID[face[i + nSegment].nVerts];
		face[i + nSegment].vert[0].vertIndex = i + 2 * nSegment;
		face[i + nSegment].vert[1].vertIndex = i + 3 * nSegment;

		if (i == nSegment - 1)
			face[i + nSegment].vert[2].vertIndex = 3 * nSegment;
		else
			face[i + nSegment].vert[2].vertIndex = i + 3 * nSegment + 1;

		if (i == nSegment - 1)
			face[i + nSegment].vert[3].vertIndex = 2 * nSegment;
		else
			face[i + nSegment].vert[3].vertIndex = i + 2 * nSegment + 1;
		for (int j = 0; j < face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i % COLORNUM;
	}
	for (i = 0; i < nSegment; i++)
	{
		face[i + 2 * nSegment].nVerts = 4;
		face[i + 2 * nSegment].vert = new VertexID[face[i + 2 * nSegment].nVerts];
		face[i + 2 * nSegment].vert[0].vertIndex = i + 3 * nSegment;
		face[i + 2 * nSegment].vert[1].vertIndex = i + nSegment;

		if (i == nSegment - 1)
			face[i + 2 * nSegment].vert[2].vertIndex = nSegment;
		else
			face[i + 2 * nSegment].vert[2].vertIndex = i + nSegment + 1;

		if (i == nSegment - 1)
			face[i + 2 * nSegment].vert[3].vertIndex = 3 * nSegment;
		else
			face[i + 2 * nSegment].vert[3].vertIndex = i + 3 * nSegment + 1;
		for (int j = 0; j < face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i % COLORNUM;
	}
	for (i = 0; i < nSegment; i++)
	{
		face[i + 3 * nSegment].nVerts = 4;
		face[i + 3 * nSegment].vert = new VertexID[face[i + 2 * nSegment].nVerts];
		face[i + 3 * nSegment].vert[0].vertIndex = i + 2 * nSegment;
		face[i + 3 * nSegment].vert[1].vertIndex = i;

		if (i == nSegment - 1)
			face[i + 3 * nSegment].vert[2].vertIndex = 0;
		else
			face[i + 3 * nSegment].vert[2].vertIndex = i + 1;

		if (i == nSegment - 1)
			face[i + 3 * nSegment].vert[3].vertIndex = 2 * nSegment;
		else
			face[i + 3 * nSegment].vert[3].vertIndex = i + 2 * nSegment + 1;
		for (int j = 0; j < face[i].nVerts; j++)
			face[i].vert[j].colorIndex = i % COLORNUM;
	}
}
void Mesh::CreateIcosahedron()
{
	double t = (sqrt(5) - 1) / 2.0;
	int i;
	numFaces = 20;
	face = new Face[numFaces];
	
	// So Dinh
	numVerts = 11;
	pt = new Point3[numVerts];
	pt[0].set(0, 1, t);
	pt[1].set(0, 1, -t);
	pt[2].set(1, t, 0);
	pt[3].set(1, -t, 0);
	pt[4].set(0, -1, -t);	
	pt[5].set(0, -1, t);
	pt[6].set(t, 0, 1);
	pt[7].set(-t, 0, 1);
	pt[8].set(t, 0, -1);
	pt[9].set(-t, 0, -1);
	pt[10].set(-1, t, 0);
	pt[11].set(-1, -t, 0);


	face[0].nVerts = 3;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 6;
	face[0].vert[2].vertIndex = 2; 
	for (i = 0; i < face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	face[1].nVerts = 3;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 6;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 2;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	face[2].nVerts = 3;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 6;
	face[2].vert[1].vertIndex = 5;
	face[2].vert[2].vertIndex = 3;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	face[3].nVerts = 3;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 5;
	face[3].vert[2].vertIndex = 6;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	face[4].nVerts = 3;
	face[4].vert = new VertexID[face[0].nVerts];
	face[4].vert[0].vertIndex = 6;
	face[4].vert[1].vertIndex = 7;
	face[4].vert[2].vertIndex = 0;
	for (i = 0; i < face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 0;

	face[5].nVerts = 3;
	face[5].vert = new VertexID[face[1].nVerts];
	face[5].vert[0].vertIndex = 2;
	face[5].vert[1].vertIndex = 3;
	face[5].vert[2].vertIndex = 8;
	for (i = 0; i < face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 1;


	face[6].nVerts = 3;
	face[6].vert = new VertexID[face[2].nVerts];
	face[6].vert[0].vertIndex = 1;
	face[6].vert[1].vertIndex = 2;
	face[6].vert[2].vertIndex = 8;
	for (i = 0; i < face[6].nVerts; i++)
		face[6].vert[i].colorIndex = 2;


	face[7].nVerts = 3;
	face[7].vert = new VertexID[face[3].nVerts];
	face[7].vert[0].vertIndex =2;
	face[7].vert[1].vertIndex =0;
	face[7].vert[2].vertIndex = 1;
	for (i = 0; i < face[7].nVerts; i++)
		face[7].vert[i].colorIndex = 3;

	face[8].nVerts = 3;
	face[8].vert = new VertexID[face[0].nVerts];
	face[8].vert[0].vertIndex = 10;
	face[8].vert[1].vertIndex = 0;
	face[8].vert[2].vertIndex = 1;
	for (i = 0; i < face[8].nVerts; i++)
		face[8].vert[i].colorIndex = 0;


	face[9].nVerts = 3;
	face[9].vert = new VertexID[face[1].nVerts];
	face[9].vert[0].vertIndex = 9;
	face[9].vert[1].vertIndex = 10;
	face[9].vert[2].vertIndex = 1;
	for (i = 0; i < face[9].nVerts; i++)
		face[9].vert[i].colorIndex = 1;


	face[10].nVerts = 3;
	face[10].vert = new VertexID[face[2].nVerts];
	face[10].vert[0].vertIndex = 9;
	face[10].vert[1].vertIndex = 1;
	face[10].vert[2].vertIndex = 8;
	for (i = 0; i < face[10].nVerts; i++)
		face[10].vert[i].colorIndex = 2;


	face[11].nVerts = 3;
	face[11].vert = new VertexID[face[3].nVerts];
	face[11].vert[0].vertIndex = 8;
	face[11].vert[1].vertIndex = 3;
	face[11].vert[2].vertIndex = 4;
	for (i = 0; i < face[11].nVerts; i++)
		face[11].vert[i].colorIndex = 3;


	face[12].nVerts = 3;
	face[12].vert = new VertexID[face[0].nVerts];
	face[12].vert[0].vertIndex = 3;
	face[12].vert[1].vertIndex = 5;
	face[12].vert[2].vertIndex = 4;
	for (i = 0; i < face[12].nVerts; i++)
		face[12].vert[i].colorIndex = 0;


	face[13].nVerts = 3;
	face[13].vert = new VertexID[face[1].nVerts];
	face[13].vert[0].vertIndex = 11;
	face[13].vert[1].vertIndex = 4;
	face[13].vert[2].vertIndex = 5;
	for (i = 0; i < face[13].nVerts; i++)
		face[13].vert[i].colorIndex = 1;


	face[14].nVerts = 3;
	face[14].vert = new VertexID[face[2].nVerts];
	face[14].vert[0].vertIndex = 11;
	face[14].vert[1].vertIndex = 7;
	face[14].vert[2].vertIndex = 10;
	for (i = 0; i < face[14].nVerts; i++)
		face[14].vert[i].colorIndex = 2;


	face[15].nVerts = 3;
	face[15].vert = new VertexID[face[3].nVerts];
	face[15].vert[0].vertIndex = 10;
	face[15].vert[1].vertIndex = 7;
	face[15].vert[2].vertIndex = 0;
	for (i = 0; i < face[15].nVerts; i++)
		face[15].vert[i].colorIndex = 3;


	face[16].nVerts = 3;
	face[16].vert = new VertexID[face[0].nVerts];
	face[16].vert[0].vertIndex = 11;
	face[16].vert[1].vertIndex = 9;
	face[16].vert[2].vertIndex = 4;
	for (i = 0; i < face[16].nVerts; i++)
		face[16].vert[i].colorIndex = 0;


	face[17].nVerts = 3;
	face[17].vert = new VertexID[face[1].nVerts];
	face[17].vert[0].vertIndex = 4;
	face[17].vert[1].vertIndex = 8;
	face[17].vert[2].vertIndex = 9;
	for (i = 0; i < face[17].nVerts; i++)
		face[17].vert[i].colorIndex = 1;


	face[18].nVerts = 3;
	face[18].vert = new VertexID[face[2].nVerts];
	face[18].vert[0].vertIndex = 7;
	face[18].vert[1].vertIndex = 11;
	face[18].vert[2].vertIndex = 5;
	for (i = 0; i < face[18].nVerts; i++)
		face[18].vert[i].colorIndex = 2;


	face[19].nVerts = 3;
	face[19].vert = new VertexID[face[3].nVerts];
	face[19].vert[0].vertIndex = 11;
	face[19].vert[1].vertIndex = 10;
	face[19].vert[2].vertIndex = 9;
	for (i = 0; i < face[19].nVerts; i++)
		face[19].vert[i].colorIndex = 3;

}

void Mesh::CreateDedocahedron()
{
	int i = 0;

	numVerts = 20;
	pt = new Point3[numVerts];
	pt[0].set(0.54, 0.54, 0.54);
	pt[1].set(0.88, 0, 0.34);
	pt[2].set(0.54, -0.54, 0.54);
	pt[3].set(0, -0.34, 0.88);
	pt[4].set(0, 0.34, 0.88);
	pt[5].set(0.88, 0, -0.34);
	pt[6].set(0.54, 0.54, -0.54);
	pt[7].set(0.34, 0.88, 0);
	pt[8].set(-0.34, 0.88, 0);
	pt[9].set(-0.54, 0.54, -0.54);
	pt[10].set(0, 0.34, -0.88);
	pt[11].set(0.54, -0.54, -0.54);
	pt[12].set(0.34, -0.88, 0);
	pt[13].set(-0.34, -0.88, 0);
	pt[14].set(-0.88, 0, 0.34);
	pt[15].set(-0.54, 0.54, 0.54);
	pt[16].set(-0.54, -0.54, -0.54);
	pt[17].set(0, -0.34, -0.88);
	pt[18].set(-0.54, -0.54, 0.54);
	pt[19].set(-0.88, 0, -0.34);

	numFaces = 12;
	face = new Face[numFaces];

	face[0].nVerts = 5;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 4;
	face[0].vert[2].vertIndex = 15;
	face[0].vert[3].vertIndex = 8;
	face[0].vert[4].vertIndex = 7;
	while (i < face[0].nVerts)
	{
		face[0].vert[i].colorIndex = 0;
		i++;
	}
		

	face[1].nVerts = 5;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 10;
	face[1].vert[1].vertIndex = 9;
	face[1].vert[2].vertIndex = 8;
	face[1].vert[3].vertIndex = 7;
	face[1].vert[4].vertIndex = 6;
	while (i < face[1].nVerts)
	{
		face[1].vert[i].colorIndex = 1;
		i++;
	}

	face[2].nVerts = 5;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 5;
	face[2].vert[3].vertIndex = 6;
	face[2].vert[4].vertIndex = 7;

	while (i < face[2].nVerts)
	{
		face[2].vert[i].colorIndex = 2;
		i++;
	}

	face[3].nVerts = 5;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 2;
	face[3].vert[2].vertIndex = 12;
	face[3].vert[3].vertIndex = 11;
	face[3].vert[4].vertIndex = 5;
	while (i < face[3].nVerts)
	{
		face[3].vert[i].colorIndex = 3;
		i++;
	}

	face[4].nVerts = 5;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 11;
	face[4].vert[1].vertIndex = 12;
	face[4].vert[2].vertIndex = 13;
	face[4].vert[3].vertIndex = 16;
	face[4].vert[4].vertIndex = 17;
	while (i < face[4].nVerts)
	{
		face[4].vert[i].colorIndex = 4;
		i++;
	}

	face[5].nVerts = 5;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 2;
	face[5].vert[1].vertIndex = 3;
	face[5].vert[2].vertIndex = 18;
	face[5].vert[3].vertIndex = 13;
	face[5].vert[4].vertIndex = 12;
	while (i < face[5].nVerts)
	{
		face[5].vert[i].colorIndex = 5;
		i++;
	}

	face[6].nVerts = 5;
	face[6].vert = new VertexID[face[6].nVerts];
	face[6].vert[0].vertIndex = 0;
	face[6].vert[1].vertIndex = 4;
	face[6].vert[2].vertIndex = 3;
	face[6].vert[3].vertIndex = 2;
	face[6].vert[4].vertIndex = 1;

	while (i < face[6].nVerts)
	{
		face[6].vert[i].colorIndex = 6;
		i++;
	}

	face[7].nVerts = 5;
	face[7].vert = new VertexID[face[7].nVerts];
	face[7].vert[0].vertIndex = 3;
	face[7].vert[1].vertIndex = 4;
	face[7].vert[2].vertIndex = 15;
	face[7].vert[3].vertIndex = 18;
	face[7].vert[4].vertIndex = 14;
	while (i < face[7].nVerts)
	{
		face[7].vert[i].colorIndex = 7;
		i++;
	}

	face[8].nVerts = 5;
	face[8].vert = new VertexID[face[8].nVerts];
	face[8].vert[0].vertIndex = 5;
	face[8].vert[1].vertIndex = 17;
	face[8].vert[2].vertIndex = 11;
	face[8].vert[3].vertIndex = 10;
	face[8].vert[4].vertIndex = 6;
	while (i < face[8].nVerts)
	{
		face[8].vert[i].colorIndex = 8;
		i++;
	}

	face[9].nVerts = 5;
	face[9].vert = new VertexID[face[9].nVerts];
	face[9].vert[0].vertIndex = 9;
	face[9].vert[1].vertIndex = 16;
	face[9].vert[2].vertIndex = 19;
	face[9].vert[3].vertIndex = 17;
	face[9].vert[4].vertIndex = 10;
	while (i < face[9].nVerts)
	{
		face[9].vert[i].colorIndex = 9;
		i++;
	}

	face[10].nVerts = 5;
	face[10].vert = new VertexID[face[10].nVerts];
	face[10].vert[0].vertIndex = 14;
	face[10].vert[1].vertIndex = 15;
	face[10].vert[2].vertIndex = 8;
	face[10].vert[3].vertIndex = 9;
	face[10].vert[4].vertIndex = 19;
	while (i < face[10].nVerts)
	{
		face[10].vert[i].colorIndex = 10;
		i++;
	}

	face[11].nVerts = 5;
	face[11].vert = new VertexID[face[11].nVerts];
	face[11].vert[0].vertIndex = 13;
	face[11].vert[1].vertIndex = 18;
	face[11].vert[2].vertIndex = 14;
	face[11].vert[3].vertIndex = 19;
	face[11].vert[4].vertIndex = 16;
	while (i < face[10].nVerts)
	{
		face[11].vert[i].colorIndex = 11;
		i++;
	}
}

void Mesh::CreateYPlane()
{
	int		nXSegment = 40, nZSegment = 40;
	float	fXWidth = 4, fZWidth = 4;

	numVerts = (nXSegment + 1) * (nZSegment + 1);
	pt = new Point3[numVerts];

	float	fXInc, fZInc;

	fXInc = fXWidth / nXSegment;
	fZInc = fZWidth / nZSegment;

	int		idx = 0;
	int		i;

	float	x, y, z;
	float	a, b, c;
	float	t;

	for (int i = 0; i < nZSegment + 1; i++)
	{
		for (int j = 0; j < nXSegment + 1; j++)
		{
			x = -fXWidth / 2 + j * fXInc;
			z = -fZWidth / 2 + i * fZInc;
			//y = 0;
			// y = 0.2*cos(5*x*x + 5*z*z);
			// y = 0.07*(x*x*x-3*x*z*z) ;
			//y= (x*x*x*x/16 - z*z*z*z/16);
			y = 0.5*sin(x*z);
			pt[idx].set(x, y, z);
			idx++;
		}
	}


	numFaces = nXSegment * nZSegment * 2;
	face = new Face[numFaces];

	idx = 0;
	for (i = 0; i < nZSegment; i++)
	{
		for (int j = 0; j < nXSegment; j++)
		{
			face[idx].nVerts = 3;
			face[idx].vert = new VertexID[face[idx].nVerts];
			face[idx].vert[0].vertIndex = i * (nXSegment + 1) + j;

			face[idx].vert[1].vertIndex = (i + 1) * (nXSegment + 1) + j + 1;
			face[idx].vert[2].vertIndex = i * (nXSegment + 1) + j + 1;
			idx++;

			face[idx].nVerts = 3;
			face[idx].vert = new VertexID[face[idx].nVerts];
			face[idx].vert[0].vertIndex = i * (nXSegment + 1) + j;

			face[idx].vert[1].vertIndex = (i + 1) * (nXSegment + 1) + j;
			face[idx].vert[2].vertIndex = (i + 1) * (nXSegment + 1) + j + 1;
			idx++;
		}
	}
}

