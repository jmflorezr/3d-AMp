#include <iostream>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkConeSource.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>

#define vtkSPtr vtkSmartPointer
#define vtkSPtrNew(Var, Type) vtkSPtr<Type> Var = vtkSPtr<Type>::New();

using namespace std;

int main()
{
    //Cambiar resolución (# de lados)
    //Cambiar color del cono
    vtkSPtrNew( cone, vtkConeSource );

    vtkSPtrNew( mapper, vtkPolyDataMapper );
    cone->SetResolution(50);
    cone->SetCenter(100,100,100);
    
    mapper->SetInputConnection( cone->GetOutputPort() );

    vtkSPtrNew( actor, vtkActor );
    actor->SetMapper( mapper );
    double r = 222.0 / 255.0; double g = 67.0 /255.0; double b = 36.0 /255.0;
    actor->GetProperty()->SetColor(r,g,b);

    vtkSPtrNew( renderer, vtkRenderer );
    renderer->AddActor(actor);
    renderer->SetBackground( 0, 0, 0 );


    vtkSPtrNew( renderWindow, vtkRenderWindow );
    renderWindow->AddRenderer( renderer );

    vtkSPtrNew( renderWindowInteractor, vtkRenderWindowInteractor );
    renderWindowInteractor->SetRenderWindow( renderWindow );

    renderer->ResetCamera();
    renderWindow->Render();
    renderWindowInteractor->Start();
    return 0;
}
