import {View, Text, StyleSheet} from "react-native";
import Setting from "@/app/interface/setting-interface";

interface SettingItemProps{
        setting: Setting,
        style: any,
}
export default function settingBlock({ setting, style }: SettingItemProps) {
        return (
            <View style={style}>
                <Text style={styles.whiteText}>{setting.name}</Text>
                <Text style={styles.whiteText}>{setting.colors.toString()}</Text>
                <Text style={styles.whiteText}>{setting.flashingPattern}</Text>
                <Text style={styles.whiteText}>{setting.direction}</Text>
                <Text style={styles.whiteText}>{setting.speed.toString()}</Text>
            </View>
        );
}

const styles = StyleSheet.create({
    whiteText: {
        color: "white",
    },
});