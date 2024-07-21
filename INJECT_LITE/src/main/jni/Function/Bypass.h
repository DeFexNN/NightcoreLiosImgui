bool BP = false;
//BehaviorType
void (*_BehaviorType_marshal)(void *point, void *oc);
void BehaviorType_marshal(void *point, void *oc){
	if(!BP){
		_BehaviorType_marshal(point, oc);
	}
}
void (*_BehaviorType_unmarshal)(void *point, void *oc);
void BehaviorType_unmarshal(void *point, void *oc){
	if(!BP){
		_BehaviorType_unmarshal(point, oc);
	}
}
void (*_BehaviorType_marshall)(void *point, void *oc, byte _encrypt_code_);
void BehaviorType_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_BehaviorType_marshall(point, oc, _encrypt_code_);
	}
}
void (*_BehaviorType_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void BehaviorType_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_BehaviorType_unmarshall(point, oc, _encrypt_code_);
	}
}
//CApplicationInspect
void (*_CApplicationInspect_handle)(void *point);
void CApplicationInspect_handle(void *point){
	if(!BP){
		_CApplicationInspect_handle(point);
	}
}
int (*_CApplicationInspect_getType)(void *point);
int CApplicationInspect_getType(void *point){
	if(!BP){
		_CApplicationInspect_getType(point);
	}
}
void (*_CApplicationInspect_marshal)(void *point, void *oc);
void CApplicationInspect_marshal(void *point, void *oc){
	if(!BP){
		_CApplicationInspect_marshal(point, oc);
	}
}
void (*_CApplicationInspect_unmarshal)(void *point, void *oc);
void CApplicationInspect_unmarshal(void *point, void *oc){
	if(!BP){
		_CApplicationInspect_unmarshal(point, oc);
	}
}
void (*_CApplicationInspect_marshall)(void *point, void *oc, byte _encrypt_code_);
void CApplicationInspect_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CApplicationInspect_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CApplicationInspect_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CApplicationInspect_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CApplicationInspect_unmarshall(point, oc, _encrypt_code_);
	}
}
//CFindRoleNameById
void (*_CFindRoleNameById_handle)(void *point);
void CFindRoleNameById_handle(void *point){
	if(!BP){
		_CFindRoleNameById_handle(point);
	}
}
int (*_CFindRoleNameById_getType)(void *point);
int CFindRoleNameById_getType(void *point){
	if(!BP){
		_CFindRoleNameById_getType(point);
	}
}
void (*_CFindRoleNameById_marshal)(void *point, void *oc);
void CFindRoleNameById_marshal(void *point, void *oc){
	if(!BP){
		_CFindRoleNameById_marshal(point, oc);
	}
}
void (*_CFindRoleNameById_unmarshal)(void *point, void *oc);
void CFindRoleNameById_unmarshal(void *point, void *oc){
	if(!BP){
		_CFindRoleNameById_unmarshal(point, oc);
	}
}
void (*_CFindRoleNameById_marshall)(void *point, void *oc, byte _encrypt_code_);
void CFindRoleNameById_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CFindRoleNameById_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CFindRoleNameById_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CFindRoleNameById_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CFindRoleNameById_unmarshall(point, oc, _encrypt_code_);
	}
}
//CGetInspectPlayerInfo
void (*_CGetInspectPlayerInfo_handle)();
void CGetInspectPlayerInfo_handle(){
	if(!BP){
		_CGetInspectPlayerInfo_handle();
	}
}
int (*_CGetInspectPlayerInfo_getType)();
int CGetInspectPlayerInfo_getType(){
	if(!BP){
		_CGetInspectPlayerInfo_getType();
	}
	return 0; 
}
void (*_CGetInspectPlayerInfo_marshal)(void *point);
void CGetInspectPlayerInfo_marshal(void *point){
	if(!BP){
		_CGetInspectPlayerInfo_marshal(point);
	}
}
void (*_CGetInspectPlayerInfo_unmarshal)(void *point);
void CGetInspectPlayerInfo_unmarshal(void *point){
	if(!BP){
		_CGetInspectPlayerInfo_unmarshal(point);
	}
}
void (*_CGetInspectPlayerInfo_marshall)(void *point, byte _encrypt_code_);
void CGetInspectPlayerInfo_marshall(void *point, byte _encrypt_code_){
	if(!BP){
		_CGetInspectPlayerInfo_marshall(point, _encrypt_code_);
	}
}
void (*_CGetInspectPlayerInfo_unmarshall)(void *point, byte _encrypt_code_);
void CGetInspectPlayerInfo_unmarshall(void *point, byte _encrypt_code_){
	if(!BP){
		_CGetInspectPlayerInfo_unmarshall(point, _encrypt_code_);
	}
}
//CGetInspectPlayerReportList
void (*_CGetInspectPlayerReportList_handle)(void *point);
void CGetInspectPlayerReportList_handle(void *point){
	if(!BP){
		_CGetInspectPlayerReportList_handle(point);
	}
}
int (*_CGetInspectPlayerReportList_getType)(void *point);
int CGetInspectPlayerReportList_getType(void *point){
	if(!BP){
		_CGetInspectPlayerReportList_getType(point);
	}
}
void (*_CGetInspectPlayerReportList_marshal)(void *point, void *oc);
void CGetInspectPlayerReportList_marshal(void *point, void *oc){
	if(!BP){
		_CGetInspectPlayerReportList_marshal(point, oc);
	}
}
void (*_CGetInspectPlayerReportList_unmarshal)(void *point, void *oc);
void CGetInspectPlayerReportList_unmarshal(void *point, void *oc){
	if(!BP){
		_CGetInspectPlayerReportList_unmarshal(point, oc);
	}
}
void (*_CGetInspectPlayerReportList_marshall)(void *point, void *oc, byte _encrypt_code_);
void CGetInspectPlayerReportList_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CGetInspectPlayerReportList_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CGetInspectPlayerReportList_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CGetInspectPlayerReportList_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CGetInspectPlayerReportList_unmarshall(point, oc, _encrypt_code_);
	}
}
//CGetInspectStatu
void (*_CGetInspectStatu_handle)(void *point);
void CGetInspectStatu_handle(void *point){
	if(!BP){
		_CGetInspectStatu_handle(point);
	}
}
int (*_CGetInspectStatu_getType)(void *point);
int CGetInspectStatu_getType(void *point){
	if(!BP){
		_CGetInspectStatu_getType(point);
	}
}
void (*_CGetInspectStatu_marshal)(void *point, void *oc);
void CGetInspectStatu_marshal(void *point, void *oc){
	if(!BP){
		_CGetInspectStatu_marshal(point, oc);
	}
}
void (*_CGetInspectStatu_unmarshal)(void *point, void *oc);
void CGetInspectStatu_unmarshal(void *point, void *oc){
	if(!BP){
		_CGetInspectStatu_unmarshal(point, oc);
	}
}
void (*_CGetInspectStatu_marshall)(void *point, void *oc, byte _encrypt_code_);
void CGetInspectStatu_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CGetInspectStatu_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CGetInspectStatu_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CGetInspectStatu_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CGetInspectStatu_unmarshall(point, oc, _encrypt_code_);
	}
}
//CGetServerReportStatus
void (*_CGetServerReportStatus_handle)(void *point);
void CGetServerReportStatus_handle(void *point){
	if(!BP){
		_CGetServerReportStatus_handle(point);
	}
}
int (*_CGetServerReportStatus_getType)(void *point);
int CGetServerReportStatus_getType(void *point){
	if(!BP){
		_CGetServerReportStatus_getType(point);
	}
}
void (*_CGetServerReportStatus_marshal)(void *point, void *oc);
void CGetServerReportStatus_marshal(void *point, void *oc){
	if(!BP){
		_CGetServerReportStatus_marshal(point, oc);
	}
}
void (*_CGetServerReportStatus_unmarshal)(void *point, void *oc);
void CGetServerReportStatus_unmarshal(void *point, void *oc){
	if(!BP){
		_CGetServerReportStatus_unmarshal(point, oc);
	}
}
void (*_CGetServerReportStatus_marshall)(void *point, void *oc, byte _encrypt_code_);
void CGetServerReportStatus_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CGetServerReportStatus_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CGetServerReportStatus_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CGetServerReportStatus_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CGetServerReportStatus_unmarshall(point, oc, _encrypt_code_);
	}
}
//CHeartBeat
void (*_CHeartBeat_handle)(void *point);
void CHeartBeat_handle(void *point){
	if(!BP){
		_CHeartBeat_handle(point);
	}
}
int (*_CHeartBeat_getType)(void *point);
int CHeartBeat_getType(void *point){
	if(!BP){
		_CHeartBeat_getType(point);
	}
}
void (*_CHeartBeat_marshal)(void *point, void *oc);
void CHeartBeat_marshal(void *point, void *oc){
	if(!BP){
		_CHeartBeat_marshal(point, oc);
	}
}
void (*_CHeartBeat_unmarshal)(void *point, void *oc);
void CHeartBeat_unmarshal(void *point, void *oc){
	if(!BP){
		_CHeartBeat_unmarshal(point, oc);
	}
}
void (*_CHeartBeat_marshall)(void *point, void *oc, byte _encrypt_code_);
void CHeartBeat_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		CHeartBeat_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CHeartBeat_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CHeartBeat_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CHeartBeat_unmarshall(point, oc, _encrypt_code_);
	}
}
//CReportCustomServer
void (*_CReportCustomServer_handle)(void *point);
void CReportCustomServer_handle(void *point){
	if(!BP){
		_CReportCustomServer_handle(point);
	}
}
int (*_CReportCustomServer_getType)(void *point);
int CReportCustomServer_getType(void *point){
	if(!BP){
		_CReportCustomServer_getType(point);
	}
}
void (*_CReportCustomServer_marshal)(void *point, void *oc);
void CReportCustomServer_marshal(void *point, void *oc){
	if(!BP){
		_CReportCustomServer_marshal(point, oc);
	}
}
void (*_CReportCustomServer_unmarshal)(void *point, void *oc);
void CReportCustomServer_unmarshal(void *point, void *oc){
	if(!BP){
		_CReportCustomServer_unmarshal(point, oc);
	}
}
void (*_CReportCustomServer_marshall)(void *point, void *oc, byte _encrypt_code_);
void CReportCustomServer_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportCustomServer_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CReportCustomServer_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CReportCustomServer_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportCustomServer_unmarshall(point, oc, _encrypt_code_);
	}
}
//CReportRoleCheating
void (*_CReportRoleCheating_handle)(void *point);
void CReportRoleCheating_handle(void *point){
	if(!BP){
		_CReportRoleCheating_handle(point);
	}
}
int (*_CReportRoleCheating_getType)(void *point);
int CReportRoleCheating_getType(void *point){
	if(!BP){
		_CReportRoleCheating_getType(point);
	}
}
void (*_CReportRoleCheating_marshal)(void *point, void *oc);
void CReportRoleCheating_marshal(void *point, void *oc){
	if(!BP){
		_CReportRoleCheating_marshal(point, oc);
	}
}
void (*_CReportRoleCheating_unmarshal)(void *point, void *oc);
void CReportRoleCheating_unmarshal(void *point, void *oc){
	if(!BP){
		_CReportRoleCheating_unmarshal(point, oc);
	}
}
void (*_CReportRoleCheating_marshall)(void *point, void *oc, byte _encrypt_code_);
void CReportRoleCheating_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportRoleCheating_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CReportRoleCheating_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CReportRoleCheating_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportRoleCheating_unmarshall(point, oc, _encrypt_code_);
	}
}
//CReportRoleCheatingById
void (*_CReportRoleCheatingById_handle)(void *point);
void CReportRoleCheatingById_handle(void *point){
	if(!BP){
		_CReportRoleCheatingById_handle(point);
	}
}
int (*_CReportRoleCheatingById_getType)(void *point);
int CReportRoleCheatingById_getType(void *point){
	if(!BP){
		_CReportRoleCheatingById_getType(point);
	}
}
void (*_CReportRoleCheatingById_marshal)(void *point, void *oc);
void CReportRoleCheatingById_marshal(void *point, void *oc){
	if(!BP){
		_CReportRoleCheatingById_marshal(point, oc);
	}
}
void (*_CReportRoleCheatingById_unmarshal)(void *point, void *oc);
void CReportRoleCheatingById_unmarshal(void *point, void *oc){
	if(!BP){
		_CReportRoleCheatingById_unmarshal(point, oc);
	}
}
void (*_CReportRoleCheatingById_marshall)(void *point, void *oc, byte _encrypt_code_);
void CReportRoleCheatingById_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportRoleCheatingById_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CReportRoleCheatingById_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CReportRoleCheatingById_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportRoleCheatingById_unmarshall(point, oc, _encrypt_code_);
	}
}
//CReportShenSu
void (*_CReportShenSu_marshal)(void *point, void *oc);
void CReportShenSu_marshal(void *point, void *oc){
	if(!BP){
		_CReportShenSu_marshal(point, oc);
	}
}
void (*_CReportShenSu_unmarshal)(void *point, void *oc);
void CReportShenSu_unmarshal(void *point, void *oc){
	if(!BP){
		_CReportShenSu_unmarshal(point, oc);
	}
}
void (*_CReportShenSu_marshall)(void *point, void *oc, byte _encrypt_code_);
void CReportShenSu_marshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportShenSu_marshall(point, oc, _encrypt_code_);
	}
}
void (*_CReportShenSu_unmarshall)(void *point, void *oc, byte _encrypt_code_);
void CReportShenSu_unmarshall(void *point, void *oc, byte _encrypt_code_){
	if(!BP){
		_CReportShenSu_unmarshall(point, oc, _encrypt_code_);
	}
}
