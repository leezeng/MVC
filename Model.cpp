#include "StdAfx.h"
#include "Model.h"

char const* const Model::DEFAULT_KEY = "MVC";

Model::~Model(void)
{
}

Model::Model( std::string const& key /*= DEFAULT_KEY*/ ):m_strKey(key)
{
	if (_Model_.find(key))
	{
		std::runtime_error("instance is exit!");
	}
	_Model_.insert(std::pair<std::string,IModel*>(key,this));
}

void Model::registerProxy( IProxy* proxy )
{
	throw std::logic_error("The method or operation is not implemented.");
}
 
IProxy* Model::removeProxy( std::string const& proxy_name )
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool Model::hasProxy( std::string const& proxy_name ) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

std::list<std::string> Model::listProxyNames( void ) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

IProxy& Model::retrieveProxy( std::string const& proxy_name )
{
	throw std::logic_error("The method or operation is not implemented.");
}

IProxy const& Model::retrieveProxy( std::string const& proxy_name ) const
{
	throw std::logic_error("The method or operation is not implemented.");
}



IModel* Model::find( std::string const& key )
{
	 return _Model_.find(key);
}

void Model::insert( std::string const& key, IModel* model )
{
	_Model_.insert(std::pair<std::string,IModel*>(key,model));
}

void Model::initializeModel( void )
{

}
template<typename _DerivedType> 
Model::Model( _DerivedType* instance, std::string const& key /*=DEFAULT_KEY*/ ): m_strKey(key)
{
	if (find(key))
		throw std::runtime_error("instance is exits!");
	insert(m_strKey, this);
	instance->_DerivedType::initializeModel();
}

Model::Model( Model const& )
{

}

Model::Model( IModel const& )
{

}

Model& Model::operator=( Model const& )
{
	return *this;
}

Model& Model::operator=( IModel const& )
{
	return *this;
}

void Model::removeModel( std::string const& key )
{
	_Model_.remove(key);
}
