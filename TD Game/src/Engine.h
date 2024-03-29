#pragma once

#include <iostream>
#include <vector>

#include "LightMapper.h"
#include "Components/Transform.h"
#include "Components/Entity.h"
#include "Camera.h"
#include "Texture.h"
#include "PostProcess.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gizmos/ImGuizmo.h>

#include "../imgui/filedialog/ImGuiFileDialog.h"

class Engine {
public:
    Engine(int width, int height);
    ~Engine();

    void SaveScene(std::string path);
    void LoadScene(std::string path);

    Camera* m_MainCamera;

    void Awake();
    void Update(float m_DeltaTime);
    void EditorLoop(float m_DeltaTime);
    void Render();

    void StartGameLoop(std::string path, std::string projectPath);

    template<typename T>
    T* FindComponent() {
        for (int i = 0; i < m_Entities.size(); i++) {
			T* component = m_Entities[i]->GetComponent<T>();
            if (component != nullptr) {
				return component;
			}
		}
		return nullptr;
    }

private:
    int m_WindowWidth;
    int m_WindowHeight;

    double mousePosX = 0, mousePosY = 0;
    float cameraX = 0, cameraY = 0;

    float lastFrameTime;

    GLFWwindow* window;

    Shader* _defaultShader;
    Shader* _lightShader;
    Shader* _postProcessShader;

    PostProcess* _postProcess;

    std::vector<float> m_FPSGraph;

    std::vector<Entity*> m_Entities;

    Entity* m_SelectedEntity;

    ImGuizmo::OPERATION m_CurrentOperation;
    ImGuizmo::MODE m_CurrentMode;

    void DrawEditor();
    std::string GetValidName(std::string name);

    void EditTransform(Entity* entity);

    std::string m_ProjectPath;
    std::vector<std::string> m_FileSystemPath;

    LightMapper* lightMapper;

    bool leftClicked = false;
};