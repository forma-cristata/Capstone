import {View, Text, StyleSheet} from "react-native";
import Setting from "@/app/interface/setting-interface";
import ColorDots from "@/app/components/ColorDots";

interface SettingItemProps{
        setting: Setting,
        style: any,
}
const SettingBlock = (props: SettingItemProps) => {
        return (
            <View style={props.style}>
                <Text style={styles.whiteText}>{props.setting.name}</Text>
                <ColorDots colors={props.setting.colors} />
                <Text style={styles.whiteText}>{props.setting.flashingPattern}</Text>
                <Text style={styles.whiteText}>{props.setting.direction}</Text>
                <Text style={styles.whiteText}>{props.setting.speed.toString()}</Text>
            </View>
        );
}

const styles = StyleSheet.create({
    whiteText: {
        color: "white",
    },
});

export default SettingBlock;
