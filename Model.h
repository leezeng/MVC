#pragma once
#include "Common.h"
#include "IModel.h"
#include <map>
#include <list>
class Model:public virtual IModel
{
public:
	static char const* const DEFAULT_KEY;
	virtual ~Model(void);
	explicit Model(std::string const& key = Model::DEFAULT_KEY);
private:
	Model(Model const&);
	Model(IModel const&);
	Model& operator=(Model const&);
	Model& operator=(IModel const&);

protected:
	static IModel* find(std::string const& key);
	static void insert(std::string const& key, IModel* model);
	virtual void initializeModel(void);

	template<typename _DerivedType>
	explicit Model(_DerivedType* instance, std::string const& key =Model::DEFAULT_KEY);

public:
	virtual void registerProxy(IProxy* proxy);
	virtual IProxy const& retrieveProxy(std::string const& proxy_name) const;
	virtual IProxy& retrieveProxy(std::string const& proxy_name);
	virtual IProxy* removeProxy(std::string const& proxy_name);
	virtual bool hasProxy(std::string const& proxy_name) const;
	virtual std::list<std::string> listProxyNames(void) const;
	static void removeModel(std::string const& key);
protected:
	std::map<std::string,IProxy*> m_mapProxy;
	std::string const m_strKey;
};

