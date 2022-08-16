#ifndef CONTROLS_HPP
#define CONTROLS_HPP

void computeMatricesFromInputs();
void mouseButtonCallback( GLFWwindow* pwin, int button, int action, int mods );
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif
