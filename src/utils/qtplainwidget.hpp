/**
 * Tucano - A library for rapid prototying with Modern OpenGL and GLSL
 * Copyright (C) 2014
 * LCG - Laboratório de Computação Gráfica (Computer Graphics Lab) - COPPE
 * UFRJ - Federal University of Rio de Janeiro
 *
 * This file is part of Tucano Library.
 *
 * Tucano Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tucano Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tucano Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __QTPLAINWIDGET__
#define __QTPLAINWIDGET__

#include <GL/glew.h>

#include <QGLWidget>
#include <QMouseEvent>
#include<iostream>

#include <tucano.hpp>

using namespace std;

namespace Tucano
{

/**
 * @brief A plain QtWidget.
 *
 * Extends QGLWidget class to include common methods for using ShaderLib
 * This widget is empty, only has initialization methods, such as GLEW.
 */
class QtPlainWidget : public QGLWidget
{
    Q_OBJECT

protected:

public:

    explicit QtPlainWidget(QWidget *parent) : QGLWidget(parent)
    {
    }

    virtual ~QtPlainWidget()
    {
    }

    /**
     * @brief Initializes openGL and GLEW.
     */
    virtual void initializeGL (void)
    {
        makeCurrent();

        QGLFormat glCurrentFormat = this->format();
        #ifdef TUCANODEBUG
        cout << "set version : " << glCurrentFormat.majorVersion() << " , " << glCurrentFormat.minorVersion() << endl;
        cout << "set profile : " << glCurrentFormat.profile() << endl;
        #endif

        glewExperimental = true;
        GLenum glewInitResult = glewInit();

        //errorCheckFunc(__FILE__, __LINE__);
        if (GLEW_OK != glewInitResult)
        {
            cerr << "Error: " << glewGetErrorString(glewInitResult) << endl;
            exit(EXIT_FAILURE);
        }
        #ifdef TUCANODEBUG
        cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl << endl;
        #endif

    }

    /**
     * @brief Resize callback for the widget.
     */
    virtual void resizeGL (void)
    {
        updateGL();
    }


protected:

    /**
     * @brief Callback for key press event.
     * @param event The key event that triggered the callback.
     */
    void keyPressEvent (QKeyEvent * event)
    {
        event->ignore();
        updateGL();
    }




signals:

public slots:

};

}
#endif
