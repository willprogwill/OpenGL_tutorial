// Include GLFW
//#include <GLFW/glfw3.h>
#include <glfw3.h>
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "controls.hpp"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}


// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 5 ); 
// Initial horizontal angle : toward -Z
//float horizontalAngle = 3.14f;
float horizontalAngle = 0.0f;
// Initial vertical angle : none
//float verticalAngle = 0.0f;
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;

static bool leftPress = false;
static bool middlePress = false;
static bool rightPress = false;


void computeMatricesFromInputs(){
        static double xlatest = 1024/2, ylatest = 768/2;
    
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	
	// Reset mouse position for next frame
	// edited by ST on 2022/06/30
	// glfwSetCursorPos(window, 1024/2, 768/2);

	// Compute new orientation
	// edited by ST on 2022/06/30
	// horizontalAngle += mouseSpeed * float(1024/2 - xpos );
	// verticalAngle   += mouseSpeed * float( 768/2 - ypos );
	if ( leftPress ) {
	    horizontalAngle += mouseSpeed * float( xpos - xlatest );
	    verticalAngle   += mouseSpeed * float( ypos - ylatest );
	}
	xlatest = xpos;
	ylatest = ypos;
	
	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	
	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f), 
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);
	
	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	// Move forward
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	// edited by ST on 2022/06/30
	// ViewMatrix       = glm::lookAt(
	// position,           // Camera is here
	// position+direction, // and looks here : at the same position, plus "direction"
	// up                  // Head is up (set to 0,-1,0 to look upside-down)
	// );

	glm::mat4 idMat	 = glm::mat4(1.0f);
	glm::mat4 transMat = glm::translate( idMat, -position );
	glm::mat4 incMat = 
	    glm::rotate( transMat, verticalAngle, glm::vec3( 1.0, 0.0, 0.0 ) );
	ViewMatrix =
	    glm::rotate( incMat, horizontalAngle, glm::vec3( 0.0, 1.0, 0.0 ) );
	
	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}


// Mouse button callback founction
void mouseButtonCallback( GLFWwindow* pwin, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT ) {
	if ( action == GLFW_PRESS ) {
	    leftPress = true;
	}
	if ( action == GLFW_RELEASE ) {
	    leftPress = false;
	}
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT ) {
	if ( action == GLFW_PRESS) {
	    rightPress = true;
	}
	if ( action == GLFW_RELEASE) {
	    rightPress = false;
	}
    }
    if (button == GLFW_MOUSE_BUTTON_MIDDLE ) {
	if ( action == GLFW_PRESS) {
	    middlePress = true;
	}
	if ( action == GLFW_RELEASE) {
	    middlePress = false;
	}
    }
}
	
