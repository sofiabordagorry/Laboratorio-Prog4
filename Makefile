SRCS := main.cpp \
        src/entidades/factory.cpp \
        src/entidades/Idioma.cpp \
        src/controladores/ControladorCurso.cpp \
        src/datatypes/DTIdioma.cpp \
        src/cu/cu_altaDeIdioma.cpp \
        src/cu/cu_consultarIdiomas.cpp \
        src/entidades/Profesor.cpp \
        src/entidades/Estudiante.cpp \
        src/controladores/ControladorUsuario.cpp \
        src/datatypes/DTEstudiante.cpp \
        src/datatypes/DTProfesor.cpp \
        src/datatypes/DTUsuario.cpp \
        src/entidades/Usuario.cpp \
        src/cu/cu_altaDeUsuario.cpp \
        src/cu/cu_consultaDeUsuario.cpp \
        src/datatypes/DTFecha.cpp \
        src/cu/cu_AltaDeCurso.cpp \
        src/datatypes/DTCurso.cpp \
        src/entidades/Curso.cpp \
        src/entidades/Inscripcion.cpp \
        src/entidades/Leccion.cpp \
        src/entidades/Ejercicio.cpp \
        src/entidades/ejercicioTraduccion.cpp \
        src/entidades/ejercicioCompletar.cpp \
        src/datatypes/DTNotificacion.cpp \
        src/datatypes/DTParEstudianteCurso.cpp \
        src/datatypes/DTInscripcion.cpp \
        src/datatypes/DTLeccion.cpp \
        src/cu/cu_consultarCurso.cpp \
        src/datatypes/DTEjercicio.cpp \
        src/cu/cu_habilitarCurso.cpp \
        src/cu/cu_AgregarLeccion.cpp \
        src/cu/cu_AgregarEjercicio.cpp \
        src/cu/cu_suscribirseANotificaciones.cpp \
        src/cu/cu_inscribirseACurso.cpp \
        src/cu/cu_cargarDatos.cpp \
        src/cu/cu_consultarNotificaciones.cpp \
        src/cu/cu_EliminarSuscripciones.cpp \
        src/cu/cu_consultarEstadisticas.cpp \
        src/datatypes/DTEstadisticaCurso.cpp \
        src/cu/cu_realizarEjercicio.cpp \
        src/cu/cu_eliminarCurso.cpp \
        src/cu/liberarMemoria.cpp

# Opciones del compilador
CXX := g++
#CXXFLAGS := -std=c++11 -w

# Nombre del ejecutable
TARGET := exe

# Regla para la compilación del ejecutable
$(TARGET): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regla para ejecutar valgrind
valgrind: $(TARGET)
	@valgrind --leak-check=full ./$(TARGET)
	
# Regla para limpiar los archivos generados
clean:
	@rm -f $(TARGET)