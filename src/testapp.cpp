#include "testapp.h"
#include "vector.h"

TestApp::TestApp(sf::ContextSettings* context_proto,std::string filename)
	: GameApp(context_proto)
{
	fail = lib3ds_file_open(filename.c_str());
	if(!fail) std::cout << "Failed to load " << filename << "." << std::endl;
	std::cout << "Constructed.\n";
	//ANYTHING AFTER THIS IS EXTRA ADDITIVE
}

float vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
};

bool TestApp::Startup()
{
	std::cout << "Starting.\n";int i;
	Lib3dsMesh* temp_mesh;
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	 {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}
	// theProgram = InitializeProgram("/home/metalhead33/Ways of Darkness Project/build-WoD-Desktop-Debug/strVertexShader.shdr","/home/metalhead33/Ways of Darkness Project/build-WoD-Desktop-Debug/strFragmentShader.shdr");
	theProgram = InitializeProgram(ReadFromFile("/home/metalhead33/Ways of Darkness Project/build-WoD-Desktop-Debug/strVertexShader.shdr"),ReadFromFile("/home/metalhead33/Ways of Darkness Project/build-WoD-Desktop-Debug/strFragmentShader.shdr"));
	//ANYTHING AFTER THIS IS EXTRA ADDITIVE
	if(fail)
	{
		mesh = new GLuint[fail->nmeshes];
		for(i = 0;i < fail->nmeshes;++i)
		{
		temp_mesh = fail->meshes[i];
		glGenBuffers(1, &mesh[i]);
		glBindBuffer(GL_ARRAY_BUFFER, mesh[i]);
		glBufferData(GL_ARRAY_BUFFER, temp_mesh->nvertices * 3 * sizeof(float),temp_mesh->vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
	else
	{
	glGenBuffers(1, &uiVBOid);
	glBindBuffer(GL_ARRAY_BUFFER, uiVBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	glGenVertexArrays(1, &uiVAOid);
	glBindVertexArray(uiVAOid);
	return true;
}



bool TestApp::Cleanup()
{
	std::cout << "Cleaning up.\n";
	//ANYTHING AFTER THIS IS EXTRA ADDITIVE
	return true;
}



void TestApp::Render()
{
	// clear the buffers
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw...
	glUseProgram(theProgram);
	//ANYTHING AFTER THIS IS EXTRA ADDITIVE
	if(fail)
	{
		;//Under construction
	}
	else
	{
	glBindBuffer(GL_ARRAY_BUFFER, uiVBOid);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	}
	glUseProgram(0);

	// end the current frame (internally swaps the front and back buffers)
	GetWindow()->display();
}



bool TestApp::Update(sf::Time deltaTime)
{
	while (GetWindow()->pollEvent(event))
	{
		if(event.type == sf::Event::Closed) return false;
		else if (event.type == sf::Event::Resized)
		{
			// adjust the viewport when the window is resized
			glViewport(0, 0, event.size.width, event.size.height);
		}
	}
	//ANYTHING AFTER THIS IS EXTRA ADDITIVE
	return true;
}
