import { Colors, ParamIds } from './Constants';
import FloatingGlobalButtons from './FloatingGlobalButtons';
import FloatingGlobalKnobs from './FloatingGlobalKnobs';
import ParameterGridSlider from './ParameterGridSlider';
import ParameterLabel from './ParameterLabel';
import React, { Component } from 'react';
import {
  EventBridge,
  Image,
  Text,
  View,
} from './Blueprint';


class ParameterGrid extends Component {
  render() {
    return (
      <View {...styles.container} {...this.props}>
        <View {...styles.contentHeader}>
          <ParameterLabel paramId={ParamIds.DELAY} {...styles.shiftLeft} {...styles.labelContainer} />
          <ParameterLabel paramId={ParamIds.FILTER_CUTOFF} {...styles.shiftLeft} {...styles.labelContainer} />
          <ParameterLabel paramId={ParamIds.WARP} {...styles.shiftLeft} {...styles.labelContainer} />
          <ParameterLabel paramId={ParamIds.ENVELOPE_THRESHOLD} {...styles.shiftLeft} {...styles.labelContainer} />
          <ParameterLabel paramId={ParamIds.MIX} {...styles.shiftLeft} {...styles.labelContainer} />
        </View>
        <View {...styles.grid}>
          <View {...styles.row}>
            <Gutter direction={-1.0}>GRAIN 1</Gutter>
            <ParameterGridSlider paramId={ParamIds.GRAIN_FREQUENCY} {...styles.cell} {...styles.notchTopRight} />
            <ParameterGridSlider paramId={ParamIds.SPRAY} {...styles.cell} {...styles.notchTopLeft} {...styles.notchTopRight} />
            <ParameterGridSlider paramId={ParamIds.SPREAD} {...styles.cell} {...styles.notchTopRight} {...styles.notchTopLeft} />
            <ParameterGridSlider paramId={ParamIds.PITCH} {...styles.cell} {...styles.notchTopLeft} {...styles.notchTopRight} />
            <ParameterGridSlider paramId={ParamIds.REVERSE} {...styles.cell} {...styles.notchTopRight} {...styles.notchTopLeft} />
            <ParameterGridSlider paramId={ParamIds.FEEDBACK_G1G2} {...styles.cell} {...styles.notchTopLeft} />
            <Gutter direction={1.0}>GRAIN 1</Gutter>
          </View>
          <View {...styles.row}>
            <Gutter direction={-1.0}>GRAIN 2</Gutter>
            <ParameterGridSlider paramId={ParamIds.GRAIN_FREQUENCY_G2} {...styles.cell} />
            <ParameterGridSlider paramId={ParamIds.SPRAY_G2} {...styles.cell} {...styles.notchBottomRight} />
            <ParameterGridSlider paramId={ParamIds.SPREAD_G2} {...styles.cell} {...styles.notchBottomLeft} />
            <ParameterGridSlider paramId={ParamIds.PITCH_G2} {...styles.cell} {...styles.notchBottomRight} />
            <ParameterGridSlider paramId={ParamIds.REVERSE_G2} {...styles.cell} {...styles.notchBottomLeft} />
            <ParameterGridSlider paramId={ParamIds.FEEDBACK_G2G1} {...styles.cell} />
            <Gutter direction={1.0}>GRAIN 2</Gutter>
          </View>
        </View>
        <View {...styles.contentFooter}>
          <ParameterLabel {...styles.labelContainer}>FREQUENCY</ParameterLabel>
          <ParameterLabel {...styles.labelContainer}>SPRAY</ParameterLabel>
          <ParameterLabel {...styles.labelContainer}>SPREAD</ParameterLabel>
          <ParameterLabel {...styles.labelContainer}>PITCH</ParameterLabel>
          <ParameterLabel {...styles.labelContainer}>REVERSE</ParameterLabel>
          <ParameterLabel {...styles.labelContainer}>FEEDBACK</ParameterLabel>
        </View>
        <FloatingGlobalKnobs {...styles.contentHeader} {...styles.floatingHeader} />
        <FloatingGlobalButtons {...styles.contentFooter} {...styles.floatingFooter} />
      </View>
    );
  }
}

function Gutter(props) {
  return (
    <View {...styles.gutter}>
      <Text {...styles.gutterText} {...{'transform-rotate': Math.PI * 0.5 * props.direction}}>
        {props.children}
      </Text>
    </View>
  );
}

const styles = {
  container: {
    'flex-direction': 'column',
  },
  contentHeader: {
    'height': `${100.0 / 9.0}%`, // Equivalent to the Chrome's header row height
    'flex': 0.0,
    'justify-content': 'center',
    'padding-left': 32.0,
    'padding-right': 32.0,
  },
  floatingHeader: {
    'position': 'absolute',
    'top': `${100.0 / 9.0 / 2.0}%`, // Half the Chrome's header row height
    'width': '100%',
  },
  contentFooter: {
    'height': `${100.0 / 9.0}%`, // Equivalent to the Chrome's header row height
    'flex': 0.0,
    'justify-content': 'center',
    'padding-left': 32.0,
    'padding-right': 32.0,
  },
  floatingFooter: {
    'position': 'absolute',
    'bottom': `${100.0 / 9.0 / 2.0}%`, // Half the Chrome's header row height
    'width': '100%',
  },
  labelContainer: {
    'flex': 0.0,
    'width': `${100.0 / 6.0}%`,
    'justify-content': 'center',
  },
  shiftLeft: {
    'position': 'relative',
    'left': '-7%',
  },
  grid: {
    'flex': 1.0,
    'flex-direction': 'column',
  },
  gutter: {
    'flex': 0.0,
    'width': 32.0,
    'justify-content': 'center',
    'align-items': 'center',
  },
  gutterText: {
    // The internal text measureFunc doesn't care about the rotation and will
    // clip the width of the text to the width of the parent if flex-shrink
    // is allowed. This 0 value guarantees that our text element width will be
    // the size of the text, then the rotation will ensure we avoid clipping.
    'flex-shrink': 0,
    'color': Colors.STROKE,
  },
  row: {
    'flex': 1.0,
    'flex-direction': 'row',
  },
  cell: {
    'flex': 1.0,
    'border-width': 2.0,
    'border-color': Colors.STROKE,
    'border-top-left-radius': '10%',
    'border-top-right-radius': '10%',
    'border-bottom-left-radius': '10%',
    'border-bottom-right-radius': '10%',
  },
  notchTopLeft: { 'border-top-left-radius': '-26%' },
  notchTopRight: { 'border-top-right-radius': '-26%' },
  notchBottomLeft: { 'border-bottom-left-radius': '-26%' },
  notchBottomRight: { 'border-bottom-right-radius': '-26%' },
};

export default ParameterGrid;