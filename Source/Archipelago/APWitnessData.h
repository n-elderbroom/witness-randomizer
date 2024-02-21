#pragma once

#include <map>
#include <set>
#include <string>

inline std::map<std::string, std::set<int64_t>> areaNameToLocationIDs = {
	{"Tutorial (Inside)", { 158000, 159510, 158001, 158002, 158003, 158004, 158005, 158006, 158007, 158008, 158009, 158010, 159512, 159513, 159517, }},
	{"Tutorial (Outside)", { 158650, 158013, 158014, 158015, 158016, 158017, 158018, 158019, 158020, 158021, 158022, 158023, 158024, 158025, 158026, 159511, 159514, 159516, 159500, 158651, 158011, 158012, 158600, 158071, 158072, 158073, 158074, 158075, 159801, }},
	{"Glass Factory", { 158027, 158601, 159002, 158028, 158029, 158030, 158031, 158032, 158033, 158034, 158035, 158036, 158037, 158038, 158039, }},
	{"Symmetry Island", { 158040, 158041, 158042, 158043, 158044, 158045, 158046, 158047, 158048, 158049, 158050, 158051, 158052, 158053, 158054, 158055, 158056, 158057, 158058, 158059, 158060, 158061, 158062, 158063, 158064, 159000, 158065, 158066, 158067, 158068, 158069, 158070, 158700, 159001, }},
	{"Desert", { 159700, 159701, 159702, 159703, 159704, 159709, 158652, 158602, 158076, 158077, 158078, 158079, 158080, 158081, 158082, 158083, 158084, 158085, 158086, 158701, 159020, 159030, 159031, 159032, 159033, 159036, 159037, 159040, 159041, 158653, 158087, 158088, 158089, 158090, 158091, 158092, 158093, 158094, 158095, 158096, 159043, 159044, 158097, 158098, 158099, 158100, 158101, 158102, 158103, 158104, 158105, 158106, 158107, 158108, 158109, 158110, 159034, 158111, 158113, 158114, 158115, 158116, 158117, 159035, }},
	{"Quarry", { 159740, 159741, 159742, 159743, 159744, 159749, 158118, 158603, 158702, 159404, 159410, 159412, 159420, 159421, 158120, 159403, 158119, 159802, 158121, 158122, 158123, 158124, 158145, 158125, 158126, 158127, 158128, 158129, 158130, 158131, 158132, 158133, 158134, 158135, 158136, 158137, 158138, 158139, 158140, 158141, 158142, 158143, 158144, 159411, 159413, 158146, 158147, 158148, 158166, 158149, 158150, 158151, 158152, 158153, 158154, 159402, 158155, 158156, 158157, 158158, 158159, 158160, 158161, 158162, 158163, 158164, 158165, 158167, 158168, 158169, 159401, }},
	{"Shadows", { 158170, 158171, 158172, 158173, 158174, 158175, 158176, 158177, 158178, 158179, 158180, 158181, 158182, 158183, 158184, 158185, 158186, 159400, 158187, 158188, 158189, 158190, 158191, 158192, 158703, }},
	{"Keep", { 159430, 159431, 158193, 158197, 158198, 158194, 158195, 158196, 158199, 158200, 158201, 158202, 158203, 158204, 158604, 158205, 158206, 158704, 158705, 159240, 159241, 159242, 159243, 159244, 159250, 159251, }},
	{"Shipwreck", { 158654, 158605, 159220, 159221, 159222, 159224, 159225, 159226, 159230, 158655, }},
	{"Monastery", { 159710, 159711, 159712, 159713, 159714, 159715, 159719, 158207, 158208, 158209, 158210, 158211, 158212, 158706, 159130, 159131, 159132, 159136, 159137, 159138, 159140, 159120, 159121, 159122, 158213, 158214, 158215, 158216, 158217, 159133, 159134, 159135, }},
	{"Town", { 159750, 159751, 159752, 159753, 159754, 159755, 159759, 158218, 158219, 158707, 158220, 158221, 158222, 158223, 158235, 158236, 158237, 158238, 158239, 158225, 158226, 158228, 159540, 159541, 159542, 159543, 159545, 159546, 159552, 159800, 158606, 158229, 159544, 158607, 158230, 158231, 158232, 158233, 158234, 158224, 158240, 158227, 159553, 158242, 158243, 158244, 158245, 158246, 158708, 159422, 159551, }},
	{"Windmill & Theater", { 159010, 159011, 159012, 158241, 158247, 158248, 158656, 158657, 158658, 158659, 158660, 158661, 158662, 158249, 158250, 158608, 159554, 159555, 159556, 159558, }},
	{"Jungle", { 158251, 158609, 158252, 158253, 158254, 158255, 158256, 158257, 158258, 158259, 158260, 158261, 158262, 158263, 158264, 158265, 158709, 158266, 159100, 159101, 159102, 159103, 159150, 159151, 159350, 159351, 158267, 158663, 159110, 158664, }},
	{"Bunker", { 158268, 158269, 158270, 158271, 158272, 158273, 158274, 158275, 158276, 158277, 158278, 158279, 158280, 158281, 158282, 158283, 158284, 158285, 159311, 158286, 159310, 158710, }},
	{"Swamp", { 158287, 159321, 159322, 159327, 158288, 158289, 158290, 158291, 158292, 158293, 158294, 158295, 158296, 158297, 158298, 158299, 158300, 158301, 158302, 159342, 159343, 158313, 158314, 158315, 158316, 158317, 158318, 158307, 158308, 158309, 158310, 158311, 158312, 159340, 158303, 158304, 158305, 158306, 158319, 158320, 158321, 158322, 158323, 158324, 158325, 158326, 158327, 159331, 159334, 158903, 158328, 158329, 158330, 158331, 158332, 159332, 159333, 158339, 158333, 159330, 159336, 158334, 158335, 158336, 158337, 158338, 158340, 158112, 158711, 158341, 158342, }},
	{"Treehouse", { 159720, 159721, 159722, 159723, 159724, 159725, 159729, 159200, 159201, 159212, 158343, 158344, 159210, 158345, 158346, 158347, 158348, 158349, 158350, 158351, 158352, 158353, 158354, 158355, 158356, 158357, 158358, 158359, 158360, 158361, 158391, 158392, 158393, 158394, 158395, 158396, 158397, 158398, 158399, 158400, 158401, 158402, 158404, 158362, 158363, 158364, 158365, 158366, 158367, 158368, 158376, 158377, 158378, 158379, 158380, 158381, 158382, 158383, 158384, 158385, 158386, 158387, 158388, 158389, 158390, 158369, 158370, 158371, 158372, 158373, 158374, 158375, 158610, 159211, 158611, 159202, 158712, 158403, }},
	{"Mountain (Outside)", { 159730, 159731, 159732, 159733, 159734, 159735, 159739, 159550, 158612, 158665, 159301, 159325, 159335, 158666, 158405, 158406, 158407, 158800, 159300, 159320, 159324, 159326, }},
	{"Mountain (Inside)", { 158408, 158409, 158410, 158411, 158412, 158413, 158414, 158415, 158416, 158417, 158418, 158419, 158420, 158421, 158422, 158423, 158424, 158425, 158426, 158427, 158428, 158429, 158430, 158431, 158432, 158433, 158434, 158435, 158436, 158437, 158438, 158613, 158439, 158440, 158441, 158442, 158443, 158444, 159313, 159314, 158614, 158445, 158446, 158522, 158523, 158524, 158525, 158526, 158527, 158528, 158529, 158530, 158531, 158532, 158533, 158534, 158535, 158536, 159312, 158447, 158448, }},
	{"Caves", { 158451, 158452, 158453, 158454, 158455, 158456, 158457, 158458, 158459, 158460, 158461, 158462, 158463, 158464, 158465, 158466, 158467, 158468, 158469, 158470, 158471, 158472, 158473, 158474, 158475, 158478, 158479, 158480, 158481, 158482, 158483, 158484, 158485, 158486, 158487, 158488, 158489, 158490, 158491, 158492, 158493, 158494, 158495, 158496, 158497, 158498, 158476, 158449, 158450, 159341, 158477, }},
	{"Challenge", { 158499, 158500, 158501, 158502, 158503, 158504, 158505, 158506, 158507, 158508, 158509, 158510, 158511, 158512, 158513, 158514, 158515, 158516, 158517, 158518, 159530, 158667, }},
	{"Tunnels", { 158668, 158519, 158520, 158521, 159557, }},
	{"Boat", { 159042, 159223, 159231, 159232, 159323, 159515, 159520, 159521, 159522, 159531, }},
};
