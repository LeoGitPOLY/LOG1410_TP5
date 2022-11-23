#include <string>

#include "Directory.h"
#include "AbsDocument.h"

int Directory::m_indent = 0;

Directory::Directory(std::string name)
	: AbsDirectoryComponent(name)
{
}

Directory::Directory(const Directory& mdd)
	: AbsDirectoryComponent(mdd.m_name)
{
	// À compléter pour copier tous les éléments contenus dans le répertoire
}

Directory* Directory::clone(void) const
{
	return new Directory(*this);
}

AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur de documents. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.

	return *this; // À remplacer 
}

DirectoryComponentIterator Directory::begin()
{
	return m_documents.begin();
}

DirectoryComponentIterator_const Directory::cbegin() const
{
	return m_documents.cbegin();
}

DirectoryComponentIterator_const Directory::cend() const
{
	return m_documents.cend();
}

DirectoryComponentIterator Directory::end()
{
	return m_documents.end();
}

void Directory::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	// À compléter pour éliminer du répertoire l'élément auquel réfère l'itérateur
}

void Directory::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments du répertoire
}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans le répertoire à la recherche d'un document
	// portant le nom reçu en argument. Si aucun document n'est trouvé, on retourne nullptr
	const AbsDocument* foundDocument = nullptr;

	/*for (auto&& dir : m_documents) {	
		if (Directory* directory = dynamic_cast<Directory*>(dir))
			dir.findDocument(productName);
		else
		{

		}
	}*/

	return foundDocument;
}

std::ostream& Directory::printToStream(std::ostream& o) const
{
	for (const DirectoryComponentPtr& dir : m_documents) { o << dir; }
	return o;
}

std::ostream& Directory::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
