.SILENT:

CLA = Classes/
OBJS = $(CLA)DataSource1D.o $(CLA)Echantillon.o $(CLA)EtudeStatistique1D.o

all:	GlissInpres

GlissInpres:	$(OBJS)
	echo "Creation de GlissInpres"
	g++ main.cpp $(OBJS) -o GlissInpres

$(CLA)DataSource1D.o:	$(CLA)DataSource1D.h $(CLA)DataSource1D.cpp
	echo "Creation de DataSource1D.o"
	g++ $(CLA)DataSource1D.cpp -c -o $(CLA)DataSource1D.o


$(CLA)Echantillon.o:	$(CLA)Echantillon.h $(CLA)Echantillon.cpp
	echo "Creation de Echantillon.o"
	g++ $(CLA)Echantillon.cpp -c -o $(CLA)Echantillon.o


$(CLA)EtudeStatistique1D.o:	$(CLA)EtudeStatistique1D.h $(CLA)EtudeStatistique1D.cpp
	echo "Creation de EtudeStatistique1D.o"
	g++ $(CLA)EtudeStatistique1D.cpp -c -o $(CLA)EtudeStatistique1D.o

clean:	
	rm $(CLA)*.o
	echo "Suppression des fichiers obj..."