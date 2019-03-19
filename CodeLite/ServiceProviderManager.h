#ifndef SERVICEPROVIDERMANAGER_H
#define SERVICEPROVIDERMANAGER_H

#include "codelite_exports.h"
#include "ServiceProvider.h"
#include <vector>
#include <unordered_map>
#include <wx/event.h>

// Similar to EventNotifier class.
// But process events in order. Each 'handler' (aka: ServiceProvider)
// Registers itself for a service with a priority. The higher the prio, it will get
// called first
class WXDLLIMPEXP_SDK ServiceProviderManager : public wxEvtHandler
{
    std::unordered_map<eServiceType, ServiceProvider::Vec_t> m_providers;
    friend class ServiceProvider;

protected:
    ServiceProviderManager();
    virtual ~ServiceProviderManager();

    void Register(ServiceProvider* provider);
    void Unregister(ServiceProvider* provider);

public:
    static ServiceProviderManager& Get();
    
    /**
     * @brief process service event
     */
    bool ProcessEvent(wxEvent& event, eServiceType type);
};
#endif // SERVICEPROVIDERMANAGER_H
