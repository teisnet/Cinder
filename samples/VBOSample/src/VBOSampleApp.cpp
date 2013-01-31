#include "Resources.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Vbo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Camera.h"
#include "cinder/ImageIo.h"

using namespace ci;
using namespace ci::app;

using std::vector;


/*** This sample demonstrates the Vbo class by creating a simple grid mesh with a texture mapped onto it.
 * The mesh has static indices and texture coordinates, but its vertex positions are dynamic.
 * It also creates a second mesh which shares static and index buffers, but has its own dynamic buffer ***/

class VboSampleApp : public AppBasic {
 public:
	void setup();
	void draw();

	gl::VboMesh		mVboMesh;
	//gl::Texture		mTexture;
	CameraPersp		mCamera;
};

void VboSampleApp::setup()
{
	std::vector<uint32_t> indices;
	std::vector<Vec3f> vertices;

	/*
	// setup the parameters of the Vbo
	int totalVertices = VERTICES_X * VERTICES_Z;
	int totalQuads = ( VERTICES_X - 1 ) * ( VERTICES_Z - 1 );
	
	// buffer our static data - the texcoords and the indices
	vector<Vec2f> texCoords;

	

	for( int x = 0; x < VERTICES_X; ++x ) {
		for( int z = 0; z < VERTICES_Z; ++z ) {
			// create a quad for each vertex, except for along the bottom and right edges
			if( ( x + 1 < VERTICES_X ) && ( z + 1 < VERTICES_Z ) ) {
				indices.push_back( (x+0) * VERTICES_Z + (z+0) );
				indices.push_back( (x+1) * VERTICES_Z + (z+0) );
				indices.push_back( (x+1) * VERTICES_Z + (z+1) );
				indices.push_back( (x+0) * VERTICES_Z + (z+1) );
			}
			// the texture coordinates are mapped to [0,1.0)
			texCoords.push_back( Vec2f( x / (float)VERTICES_X, z / (float)VERTICES_Z ) );
		}
	}
	
	
	const float timeFreq = 5.0f;
	const float zFreq = 3.0f;
	const float xFreq = 7.0f;
	float offset = getElapsedSeconds() * timeFreq;

	for( int x = 0; x < VERTICES_X; ++x ) {
		for( int z = 0; z < VERTICES_Z; ++z ) {
			float height = sin( z / (float)VERTICES_Z * zFreq + x / (float)VERTICES_X * xFreq + offset ) / 5.0f;
			vertices.push_back(Vec3f( x / (float)VERTICES_X, height, z / (float)VERTICES_Z ) );
		}
	}
	*/

	///
	int triangleCount	= 1; //mTriangles.size();
	int vertexCount		= 4; //triangleCount * 3;
	int indexCount		= 4; //triangleCount * 3;

	int i = 0;
	while(i < indexCount)
	{
		indices.push_back(i);
		i++;
	}

	//int t = 0;
	vertices.push_back(Vec3f(0.0f, 10.0f, 0));
	vertices.push_back(Vec3f( 10.0f, 10.0f, 0));
	vertices.push_back(Vec3f( 10.0f, 0.0f, 0));
	vertices.push_back(Vec3f( 0.0f, 0.0f, 0));
	///

	gl::VboMesh::Layout layout;
	layout.setStaticIndices();
	layout.setStaticPositions();
	//layout.setStaticTexCoords2d();
	//mVboMesh = gl::VboMesh( totalVertices, totalQuads * 4, layout, GL_QUADS );
	mVboMesh = gl::VboMesh( vertices.size(), indices.size(), layout, GL_QUADS );
	mVboMesh.bufferIndices( indices );
	mVboMesh.bufferPositions(vertices);
	//mVboMesh.disableClientStates();
	//mVboMesh.bufferTexCoords2d( 0, texCoords );
	mVboMesh.unbindBuffers();
	//mTexture = gl::Texture( loadImage( loadResource( RES_IMAGE ) ) );
}




void VboSampleApp::draw()
{
	gl::setMatrices( mCamera );
	
	// this pair of lines is the standard way to clear the screen in OpenGL
	gl::clear( Color( 0.15f, 0.15f, 0.15f ) );
	
	gl::drawCoordinateFrame(10.0f, 5.0f, 1.0f);
	//gl::scale( Vec3f( 10, 10, 10 ) );
	
	//mTexture.enableAndBind();
	//gl::draw( mVboMesh );
}


CINDER_APP_BASIC( VboSampleApp, RendererGl )
